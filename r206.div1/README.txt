DRAFT NOTE
================

A
---------------- 

n^2 dp is easy to get. f[i][j][l] = min(f[i - 1][j][l] + Ql, f[i - 1][j][r]) + w_i * a[i] * l

Think about divivion. Items in left are always picked up by left hand and items in right are handle by the same way. Ql is added k times if left part larger than right by k.
