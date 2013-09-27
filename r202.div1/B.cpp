#include <iostream>
#include <cstring>

#define MAXN (100100)
#define MAXM (200100)
#define MAXA (100000000)
#define MAXW (12345678987654321)
#define MAXF (10000000000000)

using namespace std;

struct edge
{
    int y, next;
} e[MAXM];
int mCnt = 1;

int n, v[MAXN], vst[MAXN];
long long w[MAXN], fac[MAXN];

void addEdge(int x, int y)
{
    e[mCnt].next = v[x];
    e[mCnt].y = y;
    v[x] = mCnt++;
}

long long gcd(long long a, long long b)
{
    long long t;
    while (b)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    long long g = gcd(a, b);
    a = a / g;
    if (b > MAXF / a) return 0;
    return a * b;
}

void dfs(int x)
{
    vst[x] = 1;
    fac[x] = 1;
    long long minW = MAXW;
    long long sonCnt = 0;
    for (int i = v[x]; i; i = e[i].next)
    {
        int y = e[i].y;
        if (vst[y]) continue;
        sonCnt++;
        dfs(y);
        if (fac[x]) fac[x] = lcm(fac[x], fac[y]);
        if (minW > w[y]) minW = w[y];
    }
    if (!sonCnt) return;
    if (fac[x] && minW)
    {
        w[x] = minW / fac[x] * fac[x] * sonCnt; 
        fac[x] = fac[x] * sonCnt;
        if (fac[x] > MAXF) fac[x] = 0;
    }
    else
    {
        w[x] = 0;
        fac[x] = 0;
    }
    //cout << "minW of " << x << " is " << minW << endl;
    //cout << "Weight " << x << " " << w[x] << endl;
    //cout << "fac " << x << " " << fac[x] << endl;
}

int main()
{
    memset(vst, 0, sizeof(vst));
    memset(v, 0, sizeof(v));
    cin >> n;
    long long all = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i + 1];
        all += w[i + 1];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addEdge(x, y);
        addEdge(y, x);
    }
    dfs(1);
    cout << all - w[1] << endl;
    return 0;
}
