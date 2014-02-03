#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define MAXK (1000000000)
#define MAXN (1000)
#define MAXP (40)

int a[MAXN][MAXN];
int n = 2, p = 0;

int add()
{
    return n++;
}

void conn(int x, int y)
{
    a[x][y] = 1;
    a[y][x] = 1;
}

void output()
{
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << (a[i][j] ? 'Y' : 'N');
        std::cout << std::endl;
    }
}

int main()
{
    int k;
    std::cin >> k;
    memset(a, 0, sizeof(a));

    int c[MAXP], tmp = k;
    int tail[MAXP];

    while (tmp)
    {
        c[p++] = tmp % 2;
        tmp /= 2;
    }

    for (int i = p - 1; i >= 0; i--)
    {
        if (!c[i])
        {
            tail[i] = add();
        }
        else
        {
            int bk1 = -1, bk2 = -1, v1, v2;
            for (int j = 0; j < i; j++)
            {
                if (bk1 < 0)
                {
                    bk1 = add();
                    bk2 = add();
                    conn(0, bk1);
                    conn(0, bk2);
                }
                else
                {
                    v1 = add();
                    v2 = add();
                    conn(bk1, v1);
                    conn(bk2, v1);
                    conn(bk2, v2);
                    conn(bk1, v2);
                    bk1 = v1;
                    bk2 = v2;
                }
            }
            if (i == p - 1)
                tail[i] = 1;
            else
                tail[i] = add();
            if (i > 0)
            {
                conn(bk1, tail[i]);
                conn(bk2, tail[i]);
            }
            else
                conn(0, tail[i]);
        }
        if (i != p - 1)
            conn(tail[i], tail[i + 1]);
    }
    output();
    return 0;
}
                

