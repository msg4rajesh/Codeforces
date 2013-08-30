#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[100100];
long long BASE = 1000000000000000000;
long long TB =   1000000000         ;
long long u1, u2;

void add(long long x)
{
		u1 += x / BASE;
		u2 += x % BASE;
		if (u2 >= BASE)
		{
				u1 += u2 / BASE;
				u2 %= BASE;
		}
}

int multiAndMore(long long m1, long long m2, long long x)
{
		long long m11 = m1 / TB, m12 = m1 % TB, m21 = m2 / TB, m22 = m2 % TB;
		long long x1 = x / TB, x2 = x % TB;
		if (x1 > 0 && m11 > 0) return 0;
		long long a11, a12, a21, a22;
		a22 = x2 * m22;
		a21 = x2 * m21 + x1 * m22;
		a12 = x2 * m12 + x1 * m21;
		a11 = x2 * m11 + x1 * m12;
		a21 += a22 / TB, a22 %= TB;
		a12 += a21 / TB, a21 %= TB;
		a11 += a12 / TB, a12 %= TB;
		if (a11 > u1 / TB) return 1;
		if (a11 < u1 / TB) return 0;
		if (a12 > u1 % TB) return 1;
		if (a12 < u1 % TB) return 0;
		if (a21 > u2 / TB) return 1;
		if (a21 < u2 / TB) return 0;
		if (a22 > u2 % TB) return 1;
		if (a22 < u2 % TB) return 0;
		return 0;
}

void div(long long x)
{
		long long l1 = 0, l2 = 0, r1 = u1, r2 = u2, m1, m2;
		while (l1 < r1 || (l1 == r1 && l2 < r2 - 1))
		{
				m1 = (l1 + r1) / 2;
				m2 = (l2 + r2) / 2 + (BASE / 2) * ((l1 + r1) % 2);
				if (multiAndMore(m1, m2, x))
				{
						r1 = m1;
						r2 = m2;
				}
				else
				{
						l1 = m1;
						l2 = m2;
				}
		}
		u1 = l1;
		u2 = l2;
}

void print()
{
		if (u1)
		{
				cout << u1;
				long long ctr = BASE;
				while (ctr > u2)
				{
						cout << '0';
						ctr /= 10;
				}
				cout << u2;
		}
		else
				cout << u2;
}

int main()
{
		cin >> n;
		for (int i = 0; i < n; i++)
				cin >> a[i];
		sort(a, a + n);
		long long u = 0;
		for (int i = 0; i < n; i++)
		{
				long long x = a[i];
				add(x);
		}
		for (int i = 1; i < n; i++)
		{
				long long x = 2 * (a[i] - a[i - 1]) * (i) * (n - i);
				add(x);
		}
		int i = 2;
		while (i < n)
		{
				if (n % i == 0)
				{
						if (((BASE % i) * (u1 % i) + u2 % i) % i == 0)
						{
								div(i);
								n /= i;
								continue;
						}
				}
				i++;
		}
		print();
		cout << ' ' << n << endl;
		return 0;
}
