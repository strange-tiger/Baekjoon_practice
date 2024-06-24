#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> bracket;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            bracket.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!bracket.empty())
                bracket.pop();
            else
                answer = false;
        }
    }

    if (!bracket.empty())
        answer = false;

    return answer;
}

int main()
{
    string str;

    cin >> str;

    if (solution(str))
        cout << "true";
    else
        cout << "false";

    return 0;
}