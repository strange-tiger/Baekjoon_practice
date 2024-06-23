#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    int cnt = 0;
    int idx = 0;
    int n = progresses.size();
    while (idx != n)
    {
        cnt = 0;
        for (int i = 0; i < n; ++i)
            progresses[i] += speeds[i];

        while (progresses[idx] >= 100)
        {
            ++cnt;
            ++idx;

            if (idx == n)
                break;
        }

        if (cnt != 0)
            answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    int N, tmp;
    vector<int> prog;
    vector<int> speed;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        prog.push_back(tmp);
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        speed.push_back(tmp);
    }

    vector<int> ans = solution(prog, speed);

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}