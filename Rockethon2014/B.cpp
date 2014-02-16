#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define MAXN (1010)

using namespace std;

int main()
{
    char s[MAXN];
    int f[MAXN];

    scanf("%s", s);
    int n = strlen(s);
    memset(f, 0, sizeof(f));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 1 - i % 2; j < i; j += 2)
            if (s[i] == s[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        if (ans < f[i])
            ans = f[i];
    }

    printf("%d\n", ans);

    return 0;
}
