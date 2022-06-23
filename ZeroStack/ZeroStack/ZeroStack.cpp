#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack<int> st;

    int K;
    cin >> K;

    while (K--)
    {
        int num;
        cin >> num;

        if (num != 0)
            st.push(num);
        else
            st.pop();
    }

    int sum = 0;
    while (st.size())
    {
        sum += st.top();
        st.pop();
    }

    cout << sum;

    return 0;
}