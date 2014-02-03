#include <iostream>
#include <cstring>
#include <cstdio>

#define MAXL (1001000)

using namespace std;

int cA[MAXL][26], cB[MAXL][26];
long long n, m, xL, yL;

int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main()
{
    cin >> n >> m;
    char x[MAXL], y[MAXL];
    scanf("%s", x);
    scanf("%s", y);
    xL = strlen(x);
    yL = strlen(y);
    long long g = gcd(xL, yL);
    memset(cA, 0, sizeof(cA));
    memset(cB, 0, sizeof(cB));
    
    for (int i = 0; i < xL; i++)
        cA[i % g][x[i] - 'a']++;
    for (int j = 0; j < yL; j++)
        cB[j % g][y[j] - 'a']++;

    long long minL = xL / g * yL, same = 0;
    for (int i = 0; i < g; i++)
        for (int j = 0; j < 26; j++)
        {
            long long p, q;
            p = cA[i][j];
            q = cB[i][j];
            same += p * q;
        }
    long long minAns = minL - same;
    long long finL = (long long)(n) * xL;
    long long ans = finL / minL * minAns;
    cout << ans << endl;
    return 0;
}
