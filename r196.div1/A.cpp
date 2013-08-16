// Codeforces Round 196, div 1, A
// by badpoet, Aug 17, 2013

#include <iostream>
#include <cmath>

using namespace std;

const long long MOD = 1000000009;

long long pow2(long long x)
{
    long long rst = 1, tmp = 2;
    while (x)
    {
        if (x & 1)
            rst = (rst * tmp) % MOD;
        tmp = tmp * tmp % MOD;
        x /= 2;
    }
    return rst;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m <= (n + 1) / k * (k - 1))
    {
        cout << m << endl;
	return 0;
    }
    m = n - m;
    
    int p = (n) / k; // p = a + b
    int q = (n) % k; // q = t + 1 or 0
    
    int t;    
    int b;
    b = min(m, p);
    t = q - max(m - b, 0);

    int a = p - b;
    // cout << a << ' ' << b << endl;
    
    // answer = k * 2^a + b * k - 1 + (t + 1 or 0)
    long long time = (pow2(a + 1) + MOD - 2) % MOD;
    // cout << a << ' ' << b << ' ' << time << endl;
    long long rst = k * time + b * (k - 1) + t;
    cout << rst % MOD << endl;
    return 0;
}
