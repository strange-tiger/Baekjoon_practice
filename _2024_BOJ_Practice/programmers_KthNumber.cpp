#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& list)
{
    int key, j;

    for (int i = 1; i < list.size(); ++i)
    {
        key = list[i];

        for (j = i - 1; j >= 0 && list[j] > key; --j)
        {
            list[j + 1] = list[j];
        }

        list[j + 1] = key;
    }
}

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> cut;

        for (int j = commands[i][0] - 1; j < commands[i][1]; ++j)
            cut.push_back(array[j]);

        sort(cut);
        answer.push_back(cut[commands[i][2] - 1]);
    }

    return answer;
}

int main()
{
    int n, t, a, b, k, tmp;
    vector<int> arr;
    vector<vector<int>> com;

    vector<int> ans;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> k;
        com.push_back({ a, b, k });
    }

    ans = solution(arr, com);
    for (int i : ans)
        cout << i << ' ';
    return 0;
}