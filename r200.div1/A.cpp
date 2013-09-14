#include <iostream>

using namespace std;

int main()
{
    long long a, b, c, x = 0;
    cin >> a >> b;
    while (b > 0)
    {
        x += a / b;
        c = a % b;
        a = b;
        b = c;
    }
    cout << x << endl;
    return 0;
}
