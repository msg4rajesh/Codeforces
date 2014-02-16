#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define inf (123456789876543)
#define MAXK (1510)
#define MAXN (3010)

using namespace std;

int n, k;
int main()
{
    long long f[MAXN][MAXK];
    long long fmk[MAXK];
    long long a[MAXN];

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int t = 1; t <= k; t++)
            f[i][t] = -inf;
        f[i][0] = 0;
    }

    for (int t = 1; t <= k; t++)
        fmk[t] = -inf;
    fmk[0] = -a[0];

    long long ans = 0;
    for (int i = 1; i < n; i++)
        for (int t = 0; t <= (i + 1) / 2 && t <= k; t++)
        {
            f[i][t] = max(0, f[i - 1][t]);
            if (t > 0)
                f[i][t] = max(f[i][t], fmk[t - 1] + a[i]);
            ans = max(ans, f[i][t]);
            fmk[t] = max(fmk[t], f[i - 1][t] - a[i]);
        }
    cout << ans << endl;

    return 0;
}
