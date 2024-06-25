#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); ++i)
    {
        q.push({ i, priorities[i] });
        pq.push(priorities[i]);
    }

    int cnt = 1;
    while (true)
    {
        pair<int, int> f = q.front();
        q.pop();

        if (f.second == pq.top())
        {
            if (f.first == location)
            {
                answer = cnt;
                break;
            }
            pq.pop();
            ++cnt;
        }
        else if (f.second != pq.top())
            q.push({ f.first, f.second });
    }

    return answer;
}

int n, tmp, ans;
vector<int> pri;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        pri.push_back(tmp);
    }
    cin >> tmp;

    ans = solution(pri, tmp);

    cout << ans;
    return 0;
}