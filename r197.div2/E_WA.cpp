#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct itv{
	int l, r;
};
itv a[1010];
int m = 0, step[4][2], flag = 0;

inline int abs(int x)
{
	if (x > 0) return x; else return -x;
}

void add_itv(int l, int r)
{
	a[m].l = l;
	a[m].r = r;
	m++;
}

void reverse(int l, int r)
{
	int t1, t2;
	for (int i = l, j = r; i <= j; i++, j--)
	{
		t1 = a[i].l, t2 = a[i].r;
		a[i].l = a[j].r, a[i].r = a[j].l;
		a[j].l = t2, a[j].r = t1;
	}
}

void check(int dep)
{
	for (int i = 0; i < m; i++)
		if (a[i].r < a[i].l) return;
	for (int i = 1; i < m; i++)
		if (a[i].l != a[i - 1].r + 1) return;
	
	int ans_dep = 0;
	for (int i = dep - 1; i >= 0; i--)
		if (step[i][0] != step[i][1]) ans_dep++;
	printf("%d\n", ans_dep);
	for (int i = dep - 1; i >= 0; i--)
		if (step[i][0] != step[i][1])
			printf("%d %d\n", step[i][0], step[i][1]);
	flag = 1;
	return;
}

int locate(int itv, int is_r)
{
	int rst = 0;
	for (int i = 0; i < itv; i++)
		rst += abs(a[i].r - a[i].l)+ 1;
	if (is_r)
		rst += abs(a[itv].r - a[itv].l);
	return rst + 1;
}

void dfs(int dep)
{
	if (flag) return;
	check(dep);
	if (dep == 3)
		return;
	for (int i = 0; i < m; i++)
		for (int j = i; j < m; j++)
		{
			reverse(i, j);
			step[dep][0] = locate(i, 0), step[dep][1] = locate(j, 1);
			dfs(dep + 1);
			reverse(i, j);
		}
}

int main()
{
	// input
	int n, t[1010];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];

	// divide
	int is_inc = 0, start = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == start) continue;
		if (i == start + 1)
		{
			if (t[i] == t[i - 1] + 1) is_inc = 1;
			else if (t[i] == t[i - 1] - 1) is_inc = 0;
			else 
			{
				add_itv(t[start], t[start]);
				start = i;
			}
		}
		else
		{
			if ((is_inc == 1 && t[i] != t[i - 1] + 1) || \
				(is_inc == 0 && t[i] != t[i - 1] - 1))
			{
				add_itv(t[start], t[i - 1]);
				start = i;
			}
		}
	}
	add_itv(t[start], t[n - 1]);

//	for (int i = 0; i < m; i++)
//		cout << a[i].l << ' ' << a[i].r << endl;
	// dfs
	dfs(0);
	return 0;
}
