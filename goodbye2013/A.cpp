#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, rst = 0, x = 0;
    cin >> a >> b;
    while (a)
    {
        rst += a;
        x += a;
        a = x / b;
        x = x % b;
    }
    cout << rst << endl;
    return 0;
}
