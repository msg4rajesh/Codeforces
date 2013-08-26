#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char avw[11];
int f[1010][12][12]; // f[has_put][diff][last_put]
int bak[1010][12][12];
int ans[1010];
int m;

inline int has(int weight)
{
	if (weight > 10 || weight < 1) return 0;
	if (avw[weight - 1] == '0')
		return 0;
	else
		return 1;
}

int main()
{
	gets(avw);
	cin >> m;
	memset(f, 0, sizeof(0));
	for (int k = 1; k < 11; k++)
		f[0][0][k] = 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 11; j++)
			for (int k = 1; k < 11; k++)
				if (f[i][j][k])
					for (int p = j + 1; p < 11; p++)
						if (has(p) && p != k)
						{
							f[i + 1][p - j][p] = 1;
							bak[i + 1][p - j][p] = k;
						}
	for (int j = 1; j < 11; j++)
		for (int k = 1; k < 11; k++)
			if (f[m][j][k])
			{
				cout << "YES" << endl;
				int j2 = j, k2 = k, tmpk;
				for (int n = m; n > 0; n--)
				{
					ans[n] = k2;
					tmpk = bak[n][j2][k2];
					j2 = k2 - j2;
					k2 = tmpk;
				}
				for (int n = 1; n <= m; n++)
					cout << ans[n] << ' ';
				cout << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}
