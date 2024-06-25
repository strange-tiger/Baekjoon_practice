#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0;
    int onBridge = 0;
    int idx = 0;
    int num = truck_weights.size();
    queue<pair<int, int>> q;

    while(idx < num)
    {
        if (!q.empty() && time >= q.front().second)
        {
            onBridge -= q.front().first;
            q.pop();
        }

        if (onBridge + truck_weights[idx] <= weight)
        {
            q.push({ truck_weights[idx], time + bridge_length });
            onBridge += truck_weights[idx];
            ++idx;
        }
        ++time;
    }

    return q.back().second + 1;
}

int main()
{
    int len, w, n;
    cin >> n >> len >> w;

    vector<int> truck(n);

    for (int i = 0; i < n; ++i)
        cin >> truck[i];

    cout << solution(len, w, truck);
    return 0;
}