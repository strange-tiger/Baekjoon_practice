#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> balance;

    char ch[100];
    int i = 0;

    bool balanced = true;

    while (1)
    {
        ch[i] = cin.get();
        if ('\n' == ch[i])
            continue;
        
        if ('.' == ch[0])
            break;

        switch (ch[i])
        {
        case '(':
            balance.push(ch[i]);
            break;

        case ')':
            if (balance.empty())
            {
                balanced = false;
            }
            else if ('(' != balance.top())
            {
                balanced = false;
            }
            else
            {
                balance.pop();
            }
            break;

        case '[':
            balance.push(ch[i]);
            break;

        case ']':
            if (balance.empty())
            {
                balanced = false;
            }
            else if ('[' != balance.top())
            {
                balanced = false;
            }
            else
            {
                balance.pop();
            }
            break;
        }

        if ('.' == ch[i])
        {
            if (!balanced || !balance.empty())
            {
                cout << "no" << '\n';
            }
            else
            {
                cout << "yes" << '\n';
            }

            while (balance.size())
            {
                balance.pop();
            }

            i = 0;
            balanced = true;

            continue;
        }

        i++;
    }

    return 0;
}