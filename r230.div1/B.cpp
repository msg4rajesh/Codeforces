#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAXN (42)
using namespace std;

inline long long min(long long a, long long b)
{
    if (a > b && b >= 0)
        return b;
    else
        return a;
}

int main()
{
    long long f[MAXN][3][3];
    long long t[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            cin >> t[i][j];
        }

    int n, k;
    cin >> n;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                f[1][i][j] = 0;
                continue;
            }
            k = 3 - i - j;
            f[1][i][j] = min(t[i][j], t[i][k] + t[k][j]);
        }
    for (int m = 2; m <= n; m++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    f[m][i][j] = 0;
                    continue;
                }
                k = 3 - i - j;
                f[m][i][j] = min(f[m - 1][i][k] + f[m - 1][k][j] + t[i][j],
                        f[m - 1][i][j] * 2 + t[i][k] + f[m - 1][j][i] + t[k][j]);
            }
    cout << f[n][0][2] << endl;
    /*
    for (int m = 1; m <= n; m++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << f[m][i][j] << ' ';
            cout << endl;
        }
        cout << endl;
    }
    */
    return 0;
}
