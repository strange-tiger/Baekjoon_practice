#include <iostream>
#include <string>
#include <stack>
using namespace std;

int i;
string str;
stack<char> notation;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for (i = 0; i < str.length(); ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            cout << str[i];
        else
        {
            if (str[i] == '(')
                notation.push(str[i]);
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!notation.empty() && notation.top() != '(')
                {
                    cout << notation.top();
                    notation.pop();
                }
                notation.push(str[i]);
            }
            else if (str[i] == '*' || str[i] == '/')
            {
                while (!notation.empty() && (notation.top() == '*' || notation.top() == '/'))
                {
                    cout << notation.top();
                    notation.pop();
                }
                notation.push(str[i]);
            }
            else if (str[i] == ')')
            {
                while (!notation.empty() && notation.top() != '(')
                {
                    cout << notation.top();
                    notation.pop();
                }
                if (notation.top() == '(')
                    notation.pop();
            }
        }
    }

    while (!notation.empty())
    {
        cout << notation.top();
        notation.pop();
    }

    return 0;
}