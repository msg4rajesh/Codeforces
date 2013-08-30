#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
		cout << 100000 << endl;
		srand(time(0));
		for (int i = 0; i < 100000; i++)
		{
				long long q1 = rand(), q2 = rand();
				cout << (q1 * q2 + 1) % 10000000 << endl;
		}
		return 0;
}
