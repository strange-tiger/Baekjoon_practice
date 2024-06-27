#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), 0);
    vector<bool> notDown(prices.size(), true);

    for (int i = 0; i < prices.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (notDown[j])
                ++answer[j];

            if (prices[j] > prices[i])
                notDown[j] = false;
        }
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