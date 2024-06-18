"fix_length is L"
def mask_sft_head[Ty, L](X: "Ty[L, L]", actual_length:"int32[2]") -> "Ty[L, L]":
    Z: Ty[L, L]
    E: Ty[L, L]
    S: Ty[L] = 0.0
    M: Ty[L] = -10000.0 # large enough value to avoid overflow in exp

    for i, j in dsl.grid(L, L, name="row_max"):
        if i >= j:
            if i >= L - actual_length[0]: 
                if j >= L - actual_length[0]: #the right bottom corner
                    if X[i, j] > M[i]:
                        M[i] = X[i, j]


    for i, j in dsl.grid(L, L, name="exp_sum"):
        if i >= j:
            if i >= L - actual_length[0]: 
                if j >= L - actual_length[0]: #the right bottom corner
                    E[i, j] = dsl.exp(X[i, j] - M[i])
                    S[i] += E[i, j]

    for i, j in dsl.grid(L, L, name="update"):
        if i >= j:
            if i >= L - actual_length[0]: 
                if j >= L - actual_length[0]: #the right bottom corner
                    Z[i, j] = E[i, j] / S[i]
                else:
                    Z[i, j] = 0
            else:
                Z[i, j] = 1.0 / (i+1+actual_length[0])
        else:
            if i < L - actual_length[0] and j >= L - actual_length[0]:
                Z[i, j] = 1.0 / (i+1+actual_length[0])
            else:
                Z[i, j] = 0
    return 

def schedule_mask_sft_head(s):
    lj = s.get_loops(s.top_func_name)["row_max"]["j"]
    s.pipeline(lj)
    lj = s.get_loops(s.top_func_name)["exp_sum"]["j"]
    s.pipeline(lj)
    lj = s.get_loops(s.top_func_name)["update"]["j"]
    s.pipeline(lj)
    return s


def masked_casual_sdp[
    Ty, H, L, D, M0, M1
](Q: "Ty[L, D]", K: "Ty[L, D]", V: "Ty[L, D]", actual_length:"int32[2]") -> "Ty[L, D]":
    
    Z: Ty[L, D]

    for h in range(H):
        Q_h: Ty[L, D // H]
        K_h: Ty[D // H, L]
        V_h: Ty[L, D // H]

        # split Q, K, V
        for i, j in dsl.grid(L, D // H, name="mha_split"):
            Q_h[i, j] = Q[i, h * (D // H) + j]
            # transposed
            K_h[j, i] = K[i, h * (D // H) + j]
            V_h[i, j] = V[i, h * (D // H) + j]

        # QK^T = (L, D//H) x (D//H, L) = (L, L)
        C_h: Ty[L, D // H] = 0
        Y: Ty[L, L] = 0
        systolic[Ty, Ty, Ty, L, D // H, L, M0, M1, "QKT"](Q_h, K_h, Y)
        #scale attention
        # s_h: Ty[1] = D // H
        # T = Y / dsl.sqrt(s_h[0])
        
        # Need to return a new value
        S = mask_sft_head[Ty, L, "sft_Y"](Y, actual_length)
        # S = softmax[Ty, L, "sft_Y"](Y)
        # YV = (L, L) x (L, D//H) = (L, D//H)
        systolic[Ty, Ty, Ty, L, L, D // H, M0, M1, "YV"](S, V_h, C_h)

        for i, j in dsl.grid(L, D // H, name="mha_merge"):
            Z[i, h * (D // H) + j] = C_h[i, j]

    return Z


def bias_add[Ty, L, D](X1: "Ty[L, D]", X2: "Ty[D]") -> "Ty[L, D]":
    Z: Ty[L, D]
    for i, j in dsl.grid(L, D):
        Z[i, j] = X1[i, j] + X2[j]
    return Z