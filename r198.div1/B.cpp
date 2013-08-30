#include <iostream>

int a[100100], sk[100100], top;
int n;

using namespace std;

int find(int x, int l, int r)
{
		if (sk[l] > x) return l;
		int mid;
		while (l < r - 1)
		{
				mid = (l + r) / 2;
				if (sk[mid] < x)
				{
						l = mid;
				}
				else
				{
						r = mid;
				}
		}
		return r;
}

int main()
{
		cin >> n;
		top = 0;
		int k;
		for (int i = 0; i < n; i++)
		{
				cin >> k;
				if (top == 0)
						sk[top++] = k;
				else
				{
						if (k > sk[top - 1])
								sk[top++] = k;
						else
						{
								sk[find(k, 0, top - 1)] = k;
						}
				}
		}
		cout << top << endl;
		return 0;
}
