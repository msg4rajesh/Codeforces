#include <iostream>
#include <string>

using namespace std;
const int MAXN = 100100;
int top = 0;
char stack[MAXN];

int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if (!top)
        {
            stack[top++] = s[i];
        }
        else
        {
            if (s[i] == stack[top - 1])
                top--;
            else
                stack[top++] = s[i];
        }
    if (!top)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
