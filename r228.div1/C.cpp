#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define MAXN (110)

int main()
{
    long long sa = 0, sb = 0;
    int n, s, x, m = 0, tar[MAXN];
    using namespace std;

    cin >> n;
    while (n--)
    {
        cin >> s;
        for (int i = 1; i <= s; i++)
        {
            cin >> x;
            if (i * 2 - 1 < s)
                sa += x;
            if (i * 2 - 1 == s)
                tar[m++] = x;
            if (i * 2 - 1 > s)
                sb += x;
        }
    }
    sort(tar, tar + m);
    int g = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (!g)
        {
            sa += tar[i];
            g = 1;
        }
        else
        {
            sb += tar[i];
            g = 0;
        }
    }
    cout << sa << ' ' << sb << endl;
    return 0;
}

