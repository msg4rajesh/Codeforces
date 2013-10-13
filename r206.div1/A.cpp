#include <iostream>

#define MAXN (100100)

using namespace std;

int main()
{
    int n;
    long long w[MAXN], sL, sR, fL, fR, qL, qR;
    long long tmp, ans = 12345678987654321;

    cin >> n >> fL >> fR >> qL >> qR;
    sL = sR = 0;
    for (int i = 0; i < n; i++)
    {   
        cin >> w[i];
        sR += w[i];
    }

    for (int i = 0; i <= n; i++)
    {
        tmp = sL * fL + sR * fR;
        if (i > (n - i))
        {
            if (i - n + i > 1)
                tmp += (i - (n - i) - 1) * qL;
        }
        else
        {
            if (n - i - i > 1)
                tmp += ((n - i) - i - 1) * qR;
        }
        if (tmp < ans)
            ans = tmp;
        if (i == n) break;
        sL += w[i];
        sR -= w[i];
    }
    cout << ans << endl;
    return 0;
}


