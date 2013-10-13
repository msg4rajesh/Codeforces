#include <iostream>
#include <algorithm>

using namespace std;

struct rule{
    int a[6], sL;
} r[5][800];
int nRule[5] = {0};

int f[19][5];
int bak[19][5];
int y[20];
int flag;
int glo;

int cur[6];
void prepare(int p, int now)
{
    if (p == 6)
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += cur[i];
        }
        int id = sum / 10;

        r[id][nRule[id]].sL = sum % 10;
        for (int i = 0; i < 6; i++)
        {
            r[id][nRule[id]].a[i] = cur[i];
        }
        nRule[id]++;
        return;
    }
    cur[p] = now;
    prepare(p + 1, now);
    if (now < 4)
    {
        cur[p] = 4;
        prepare(p + 1, 4);
    }
    if (now < 7)
    {
        cur[p] = 7;
        prepare(p + 1, 7);
    }
}

int go[6];

void out()
{
    for (int i = 0; i < 5; i++)
        cout << go[i] << '+';
    cout << go[5] << endl;
}

void dfs(int p, int b)
{
    if (flag) return;
    if (p < 0)
    {
        if (b == 0)
        {
            flag = 1;
            out();
        }
        return;
    }
    if (f[p][b]) return;
    f[p][b] = 1;
    for (int i = 0; i < nRule[b]; i++)
    {
        if (y[p] >= r[b][i].sL)
        {
            for (int j = 0; j < 6; j++)
            {
                go[j] = go[j] * 10 + r[b][i].a[j];
            }
            dfs(p - 1, y[p] - r[b][i].sL);
            for (int j = 0; j < 6; j++)
                go[j] /= 10;
        }
    }
}

void solve(long long x)
{
    memset(f, 0, sizeof(f));
    memset(bak, 0, sizeof(bak));
    memset(go, 0, sizeof(go));
    flag = 0;
    int t = 0;
    while (x)
    {
        y[t] = x % 10;
        x = x / 10;
        t++;
    }
    glo = t;
    dfs(t - 1, 0);
    if (!flag)
        cout << -1 << endl;
}

int main()
{
    prepare(0, 0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long x;
        cin >> x;
        solve(x);
    }
    return 0;
}
