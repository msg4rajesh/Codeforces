#include <cstdio>
#include <cstring>

int c1, c2, c3;

using namespace std;

int main()
{
	char s[110];
	c1 = c2 = c3 = 0;
	gets(s);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '1')
			c1++;
		else if (s[i] == '2')
			c2++;
		else if (s[i] == '3')
			c3++;
	}
    for (int i = 0; i < strlen(s); i++)
		if (i % 2 == 0)
		{
			if (c1 > 0)
			{
				c1--;
				s[i] = '1';
			}
			else if (c2 > 0)
			{
				c2--;
				s[i] = '2';
			}
			else if (c3 > 0)
			{
				c3--;
				s[i] = '3';
			}
		}
	puts(s);
	return 0;
}
