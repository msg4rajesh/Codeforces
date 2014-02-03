#include <cstdio>
#include <iostream>

#define MAXN (200100)

using namespace std;

int main()
{
    int dir[MAXN], n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dir[i];

    long long ans = 0, tmp = 0, la[MAXN], ra[MAXN];

    la[0] = ra[n - 1] = 0;
    for (int i = 1; i < n; i++)
        if (dir[i - 1] == 1)
            la[i] = la[i - 1] + 1;
        else
            la[i] = la[i - 1];
    for (int i = n - 2; i >= 0; i--)
        if (dir[i + 1] == 0)
            ra[i] = ra[i + 1] + 1;
        else
            ra[i] = ra[i + 1];
    for (int i = 0; i < n; i++)
        ans = ans + la[i] + ra[i];
    for (int i = 0; i < n; i++)
        if (dir[i] == 1)
        {
            ans -= n - 1 - i;
            tmp++;
        }
    for (int i = n - 1; i >= 0; i--)
        if (dir[i] == 0)
        {
            ans -= i - tmp;
        }
        else
        {
            tmp--;
        }
    cout << ans << endl;
    return 0;
}
