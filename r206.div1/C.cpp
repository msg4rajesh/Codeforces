#include <iostream>
#include <cstring>

#define MAXA (2000100)
using namespace std;

int main()
{
    int a[MAXA], b[MAXA];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int n, k, t;
    
    int minA = MAXA, maxA = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t < minA) minA = t;
        if (t > maxA) maxA = t;
        a[t] = 1;
        if (t - k - 1 > 0)
            b[t - k - 1] = 1;
    }

    for (int i = 1; i <= 2 * maxA; i++)
    {
        a[i] = a[i] + a[i - 1];
        b[i] = b[i] + b[i - 1];
    }

    // x <= k + 1 must be avaliable
    int ans = (k + 1 > minA ? minA : k + 1);
    for (int x = minA; x >= k + 2; x--)
    {
        // check if x is avaliable
        int flag = 1, cntB, cntA;
        for (int t = 1; t * x < maxA; t++)
        {
            if (t == 1)
                cntB = b[t * x - 1];
            else
                cntB = b[t * x - 1] - b[(t - 1) * x - 1];
            cntA = a[(t + 1) * x - 1] - a[t * x - 1];
            if (cntA != cntB)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans = x;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

