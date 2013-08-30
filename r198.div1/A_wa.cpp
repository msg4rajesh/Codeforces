#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

/* bigNum struct by badpoet */

struct bigNum
{
#define BNLEN (10)
#define BNBASE (10000)
	int n, sgn; // sgn = 1 or -1
	long d[BNLEN];
}

bigNum()
{
	n = 0;
	sgn = 1;
}

bigNum operator =(bigNum a, bigNum b)
{
	a.n = b.n;
	a.sgn = b.sgn;
	for (int i = 0; i < b.n; i++)
		a.d[i] = b.d[i];
}

bool operator ==(bigNum a, bigNum b)
{
	if (a.sgn != b.sgn) return false;
	if (a.n != b.n) return false;
	for (int i = 0; i < b.n; i++)
		if (a.d[i] != b.d[i])
			return false;
	return true;
}

bool operator <(bigNum a, bigNum b)
{
	if (a.sgn < b.sgn) return true;
	if (a.sgn > b.sgn) return false;
	if (a.sgn < 0)
	{
		if (a.n > b.n)
			return true;
		else if (a.n < b.n)
			return false;
		for (int i = 0; i < a.n; i++)
			if (a.n > b.n)
				return true;
			else if (a.n < b.n)
				return false;
	}
	return false;
}
int n;
long long a[100100];
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

void div(long long x)
{
		long long t1 = u1 / n;
		long long r1 = u1 % n;
		long long tt = r1 * BASE + u2;
		long long t2 = tt / n;
		u1 = t1;
		u2 = t2;
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
		long long v = n;
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
						if (BASE % i * u1 + u2 % i == 0)
						{
								div(i);
								n /= i;
						}
				}
				i++;
		}
		print();
		cout << ' ' << n << endl;
		return 0;
}
