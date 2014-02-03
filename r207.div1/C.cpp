#include <iostream>
#include <cstring>

#define MAXST (1234567)

using namespace std;

int cnt[5];

int glAns = 12345678;

int searchTime = 0;
void dfs(int a, int b, int c, int d, int now)
{
    if (searchTime > MAXST)
        return;
    else
        searchTime++;
    if (a == b)
    {
        now = now + a;
        if (now < glAns) glAns = now;
        return;
    }

    if (a >= 2) dfs(a - 2, b + 1, c, d, now + 1);
    if (a >= 1 && b >= 1) dfs(a - 1, b - 1, c + 1, d, now + 1);
    if (b >= 2) dfs(a + 1, b - 2, c + 1, d, now + 1);
    if (a >= 1 && c >= 1) dfs(a - 1, b, c - 1, d + 1, now + 1);
    if (b >= 1 && d >= 1) dfs(a, b - 1, c + 2, d - 1, now + 1);
    if (c > 0 && a >= 2 && b >= 1) dfs(a - 2, b - 1, c, d + 1, now + 2);
    if ((c > 0 || d > 0) && a > 1 && b > 1) dfs(a - 1, b - 1, c + 1, d, now + 2);
    if (c + d < 100 && c >= 1) dfs(a, b, c - 1, d + 1, now + 1);
}

int main()
{
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    while (n--)
    {
        int k;
        cin >> k;
        cnt[k]++;
    }
    n = cnt[1] +  2 * cnt[2] + 3 * cnt[3] + 4 * cnt[4];
    if (n == 1 || n == 2 || n == 5)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0, a = cnt[1], b = cnt[2], c = cnt[3], d = cnt[4];
    while (a >= b + 6)
    {
        ans++;
        a -= 2;
        b += 1;
    }
    while (b >= a + 6)
    {
        ans++;
        a += 1;
        b -= 2;
        c++;
    }
    dfs(a, b, c, d, ans);
    cout << glAns << endl;
    return 0;
}
