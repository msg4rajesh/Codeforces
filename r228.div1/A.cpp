#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))

#define MAXN (110)

int main()
{
    int n, x[MAXN], m[MAXN];
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> x[i];
    std::sort(x, x + n);
    memset(m, 0, sizeof(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (m[j] <= x[i])
            {
                m[j]++;
                break;
            }
    for (int j = 0; j < n + 1; j++)
        if (m[j] == 0)
        {
            std::cout << j << std::endl;
            break;
        }
    return 0;
}

