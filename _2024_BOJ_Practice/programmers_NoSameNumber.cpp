#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;

    q.push(arr[0]);
    for (int i = 1; i < arr.size(); ++i)
    {
        if (q.back() == arr[i])
            continue;
        q.push(arr[i]);
    }

    while (!q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}

int n;

int main()
{
    cin >> n;

    int tmp;
    vector<int> input;
    vector<int> output;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        input.push_back(tmp);
    }

    output = solution(input);

    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << ' ';

    return 0;
}