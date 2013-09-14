#include <iostream>

using namespace std;

const int MAXN = 100100;
long long h[MAXN], p[MAXN];
int n, m;

inline long long abs(long long x)
{
    if (x >= 0) return x;
    else return -x;
}

inline long long dis(int i, int j, int k)
{
    if (p[k] <= h[i])
        return h[i] - p[j];
    if (p[j] >= h[i])
        return p[k] - h[i];
    return p[k] - p[j] + min(h[i] - p[j], p[k] - h[i]);
}

int enough(long long maxs)
{
    // cout << "now calculating " << maxs << endl;
    int i = 0, j = 0, k = 0;
    while (i < n)
    {
        while ((k < m) && dis(i, j, k) <= maxs) k++;
        if (k == m)
            return 1;
        if (j == k)
        {
            i++;
            continue;
        }
        j = k;
        i++;
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> p[i];

    // calc ceiling
    long long minp = 123456789876, maxp = 0;
    for (int i = 0; i < m; i++)
    {
        if (p[i] > maxp) maxp = p[i];
        if (p[i] < minp) minp = p[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (h[i] > maxp) maxp = h[i];
        if (h[i] < minp) minp = h[i];
    }
    long long l = 0, r = 2 * (maxp - minp) + 1;
    if (enough(0))
    {
        cout << 0 << endl;
        return 0;
    }
    while (l < r - 1)
    {
        long long mid = (l + r) / 2;
        if (enough(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return 0;
}
