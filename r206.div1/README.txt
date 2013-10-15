DRAFT NOTE
================

A&C were accepted, while E got WA with no time to correct it.

A
---------------- 

n^2 dp is easy to get. f[i][j][l] = min(f[i - 1][j][l] + Ql, f[i - 1][j][r]) + w_i * a[i] * l

Think about divivion. Items in left are always picked up by left hand and items in right are handle by the same way. Ql is added k times if left part larger than right by k.

C
---------------- 

Find the biggest X, and a[i] <= tx <= a[i] - k
If a[i] / x != (a[i] - k - 1) / x, x can be the final X
Every x (x <= k + 1) is avaliable.

Certain length interval...
check every x, check every tx, if b in (t-1)x + 1 ~ tx same with tx + 1 ~ (t+1)x, cost (length/x)
eg.1
3 6 10 12 13 16
1 4 8 10 11 14
