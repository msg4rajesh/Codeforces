#include <iostream>
#include <string>
#include <cstring>

#define MAXN (3010)
#define BASE (1000000007)

using namespace std;

int f[MAXN][MAXN], g[MAXN][MAXN];
int n, m;
char map[MAXN][MAXN];
const int dir[4][4] = {{0, 1, 0, 1},
                       {1, 0, 0, 1},
                       {0, 1, 1, 0},
                       {1, 0, 1, 0}};

int main()
{
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, tmp);
        for (int j = 1; j <= m; j++)
            map[i][j] = tmp[j - 1];
        map[i][m + 1] = '#';
    }
    for (int j = 1; j <= m; j++)
        map[n + 1][j] = '#';
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    f[1][1] = 1;
    for (int k = 2; k < n + m; k++)
    {
        //cout << "title " << k << endl;
        memcpy(g, f, sizeof(g));
        memset(f, 0, sizeof(f));
        //for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << i << ' ' << j << ' ' << g[i][j] << endl;
        for (int i = 1; i <= min(n, k - 1); i++)
            for (int j = i; j <= min(n, k - 1); j++)
                if (g[i][j])
                {
                    int x1 = i, y1 = k - i;
                    int x2 = j, y2 = k - j;
                    for (int d = 0; d < 4; d++)
                    {
                        if (k != n + m - 1 && x1 + dir[d][0] >= x2 + dir[d][2]) continue;
                        if (map[x1 + dir[d][0]][y1 + dir[d][1]] == '#')
                            continue;
                        if (map[x2 + dir[d][2]][y2 + dir[d][3]] == '#')
                            continue;
                        f[x1 + dir[d][0]][x2 + dir[d][2]] = (f[x1 + dir[d][0]][x2 + dir[d][2]] + g[x1][x2]) % BASE;
                    }
                }
    }
    cout << f[n][n] << endl;
    return 0;
}
