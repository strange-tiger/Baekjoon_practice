#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<char> st;

    int T;
    cin >> T;

    while (T--)
    {
        bool VPS = true;
        string par;
        cin >> par;

        for (int i = 0; i < par.size(); i++)
        {
            char ch = par.c_str()[i];
            if ('(' == ch)
            {
                st.push(ch);
            }
            else if (')' == ch)
            {
                if (!st.empty())
                    st.pop();
                else
                    VPS = false;
            }
        }

        if (!VPS || !st.empty())
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }

        while (st.size())
        {
            st.pop();
        }
    }

    return 0;
}