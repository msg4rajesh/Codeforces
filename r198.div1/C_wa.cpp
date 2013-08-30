#include <iostream>
#include <cstring>

long long B = 1000000007;
long long C[2010][2010], A[2010][2010], D[2010];
int n;

using namespace std;

int main()
{
		int x = 0, y = 0;
		int flag[2010] = {0};
		int app[2010] = {0};

		memset(A, 0, sizeof(A));
		memset(C, 0, sizeof(C));
		memset(D, 0, sizeof(D));

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
				cin >> flag[i];
				if (flag[i] > 0)
						app[flag[i]] = 1;
		}
		for (int i = 1; i <= n; i++)
				if (flag[i] == i)
				{
						cout << "0" << endl;
						return 0;
				}
		for (int i = 1; i <= n; i++)
		{
				if (app[i] == 0 && flag[i] == -1)
						x++;
				if (app[i] == 0 && flag[i] > 0)
						y++;
		}
		
		//cout << x << ' ' << y << endl;

		for (int i = 0; i <= n; i++)
				for (int j = 0; j <= i; j++)
				{
						if (j == 0 || i == 0)
						{
								C[i][j] = 1;
								A[i][j] = 1;
						}
						else
						{
								C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % B;
								A[i][j] = A[i][j - 1] * (i - j + 1) % B;
						}
				}
		D[0] = 1;
		D[1] = 0;
		D[2] = 1;
		for (int i = 3; i <= n; i++)
				D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % B;
		long long ans = 0;
		for (int i = 0; i <= std::min(x, y); i++)
		{
				ans = (ans + C[x][i] * D[x - i] % B * A[y][i] % B * A[y][y] % B) % B;
				//cout << C[x][i] << ' ' << D[x - i] << ' ' << A[y][i] << ' ' << A[y][y] << endl;
		}
		cout << ans << endl;
		return 0;
}

