#include <iostream>

#define MAXN (300100)

using namespace std;

int n, m;
int fa[MAXN], ans[MAXN], skip[MAXN];
int l, r, x;

void setSet(int s, int t)
{
    fa[s] = t;
    if (skip[s] > skip[t]) skip[t] = skip[s];
}

int getSet(int x)
{
    if (x > n) return n + 1;
    if (x == fa[x]) return x;
    int rst = getSet(fa[x]);
    fa[x] = rst;
    return rst;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        skip[i] = i;
        fa[i] = i;
        ans[i] = 0;
    }
    while (m--)
    {
        cin >> l >> r >> x;
        for (int i = getSet(l); i <= getSet(r); i = getSet(skip[i] + 1))
        {
            if (getSet(i) == x) continue;
            ans[i] = x;
            setSet(i, getSet(x));
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}

