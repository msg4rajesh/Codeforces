#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	long long round = 0;
	long long now, last = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> now;
		if (now < last) round++;
		last = now;
	}
	cout << round * n + now - 1;
	return 0;
}
