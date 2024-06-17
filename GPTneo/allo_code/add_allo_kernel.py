"fix_length is L"
def mask_softmax_per_head[Ty, L](X: "Ty[L, L]", actual_length:"int32[2]") -> "Ty[L, L]":
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

def schedule_mask_softmax_per_head(s):
    lj = s.get_loops(s.top_func_name)["row_max"]["j"]
    s.pipeline(lj)
    lj = s.get_loops(s.top_func_name)["exp_sum"]["j"]
    s.pipeline(lj)
    lj = s.get_loops(s.top_func_name)["update"]["j"]
    s.pipeline(lj)
    return s