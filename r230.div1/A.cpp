#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int qua = 0, lst = 0, now, on = 1;
    for (int i = n - 1; i > 0; i--)
    {
        now = sqrt((long long)n * n - (long long)i * i);
        if ((long long)now * now + (long long)i * i == (long long)n * n)
            on = 1;
        else
            on = 0;
        qua += now - lst + (now == lst ? 1 : 0);
        lst = now;
    }
    if (n)
        cout << (qua + 1) * 4 << endl;
    else
        cout << 1 << endl;
    return 0;
}
