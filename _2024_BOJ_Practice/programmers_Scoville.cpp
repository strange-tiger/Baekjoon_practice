#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> heap;

    for (int s : scoville)
        heap.push(s);

    int mix;
    while (heap.size() > 1 && heap.top() < K)
    {
        mix = heap.top();
        heap.pop();

        mix += heap.top() * 2;
        heap.pop();
        heap.push(mix);

        ++answer;
    }

    if (heap.top() < K)
        return -1;

    return answer;
}

int main()
{
    int n, k, tmp;
    vector<int> sco;

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        sco.push_back(tmp);
    }

    cout << solution(sco, k);
    return 0;
}