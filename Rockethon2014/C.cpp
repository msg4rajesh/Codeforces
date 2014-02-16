#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAXN (200100)

using namespace std;

int n, k;
struct oppo
{
    int e, p;
} op[MAXN], op2[MAXN];

int op_cmp(oppo a, oppo b)
{
    if (a.p > b.p) return true;
    else return false;
}

int op2_cmp(oppo a, oppo b)
{
    if (a.e < b.e) return true;
    else return false;
}

long long check(int a)
{
    int cnt_eql = 0, tagl = n, tagr = -1, need;
    for (int i = n - 1; i >= 0 && op[i].p <= a; i--)
    {
        if (op[i].p >= a - 1)
        {
            if (tagr < 0)
                tagr = i;
            cnt_eql++;
        }
        tagl = i;
    }
    if (tagl > k - 1)
        return -1;
    if (tagr < k - 1)
        need = 0;
    else
        need = tagr - k + 2;
    long long rst = 0;
    int now = 0;
    for (int i = 0; i < n && now < a; i++)
    {
        if (a - now > need || (op2[i].p >= a - 1 && op2[i].p <= a))
        {
            rst += op2[i].e;
            now += 1;
            if (op2[i].p >= a - 1 && op2[i].p <= a)
                need -= 1;
        }
    }
    if (now < a || need > 0)
        return -1;
    else
        return rst;
}

int main()
{

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &(op[i].p), &(op[i].e));
        op2[i] = op[i];
    }

    sort(op, op + n, op_cmp);
    sort(op2, op2 + n, op2_cmp); 

    int lb = 0, rb = n, mid; // [)
    long long ans;
    if (check(rb) < 0)
    {
        cout << -1 << endl;
    }
    else if ((ans = check(lb)) >= 0)
    {
        cout << ans << endl;
    }
    else
    {
        while (lb < rb - 1)
        {
            mid = (lb + rb) / 2;
            if ((ans = check(mid)) >= 0)
                rb = mid;
            else
                lb = mid;
        }
        ans = -1;
        for (int i = rb; i <= min(rb + 2, n); i++)
        {
            long long tmp = check(i);
            if ((tmp < ans || ans == -1) && tmp >= 0) ans = tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
