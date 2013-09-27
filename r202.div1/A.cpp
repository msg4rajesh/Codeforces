#include <iostream>

#define MAXN (100100)

using namespace std;

long long a[MAXN], maxA;
int n;

int check(long long rd)
{
    if (rd < maxA) return 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += rd - a[i];
    if (sum >= rd) return 1;
    return 0;
}
int main()
{
    cin >> n;
    maxA = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxA) maxA = a[i];
    }
    long long l, r;
    l = 0; // absolutely not enough
    r = a[0] + maxA; // absolutely enough
    while (l < r - 1)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
    return 0;
}
