#include <cstdio>
#include <iostream>

using namespace std;

int n, m, ex_n, full_n;
int f[300000];

int main()
{
	cin >> n >> m;
	ex_n = 1 << n;
	full_n = ex_n << 1;
	for (int i = 0; i < ex_n; i++)
		cin >> f[i + ex_n];
	int depth = 0;
	for (int i = ex_n - 1; i > 0; i--)
	{
		if (depth % 2 == 0)
			f[i] = f[i * 2] | f[i * 2 + 1];
		else
			f[i] = f[i * 2] ^ f[i * 2 + 1];
		if (((i - 1) & (i)) == 0) depth += 1;
	}

	while (m--)
	{
		int p, b;
		cin >> p >> b;
		depth = 0;
		p += ex_n - 1;
		f[p] = b;
		p /= 2;
		while (p)
		{
			if (depth % 2 == 0)
				f[p] = f[p * 2] | f[p * 2 + 1];
			else
				f[p] = f[p * 2] ^ f[p * 2 + 1];
			depth += 1;
			p /= 2;
		}
		cout << f[1] << endl;
	}

	return 0;
}
