#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

#define MAXN (110)

using namespace std;

int main()
{
    char s[MAXN];
    scanf("%s", s);

    int eve = 0, csc = 0;
    char now = 'N';
    int n = strlen(s);
    s[n] = 'N';
    for (int i = 0; i <= n; i++)
    {
        if (s[i] != now)
        {
            now = s[i];
            if (csc > 0 && csc % 2 == 0)
            {
                eve += 1;
            }
            csc = 1;
        }
        else
        {
            csc += 1;
        }
    }
    printf("%d\n", eve);
    return 0;
}
