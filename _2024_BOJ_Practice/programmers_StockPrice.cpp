#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices)
{
    int length = prices.size();
    vector<int> answer(length);
    stack<int> notDown;

    for (int i = 0; i < length; ++i)
        answer[i] = length - i - 1;

    notDown.push(0);

    for (int i = 1; i < length; ++i)
    {
        while (!notDown.empty() && prices[i] < prices[notDown.top()])
        {
            answer[notDown.top()] = i - notDown.top();
            notDown.pop();
        }
        notDown.push(i);
    }

    return answer;
}

int main()
{
    int n, tmp;
    vector<int> prices;
    vector<int> ans;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        prices.push_back(tmp);
    }

    ans = solution(prices);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
}