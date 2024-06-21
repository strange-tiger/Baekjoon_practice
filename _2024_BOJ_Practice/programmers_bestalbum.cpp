#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
    {
        if (a.second.first == b.second.first)
        {
            return a.second.second < b.second.second;
        }
        return a.second.first > b.second.first;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genreNum;

    for (string g : genres)
        genreNum[g] = 0;
    for (int i = 0; i < plays.size(); ++i)
        genreNum[genres[i]] += plays[i];

    vector<pair<int, pair<int, int>>> album;

    for (int i = 0; i < plays.size(); ++i)
        album.push_back({ genreNum[genres[i]], { plays[i], i }});

    sort(album.begin(), album.end(), cmp);

    for (string g : genres)
        genreNum[g] = 0;

    int code;
    for (int i = 0; i < album.size(); ++i)
    {
        code = album[i].second.second;
        
        if (genreNum[genres[code]] == 2)
            continue;
        ++genreNum[genres[code]];

        answer.push_back(code);
    }

    return answer;
}

int main()
{
    int n, tmp;
    string str;
    vector<string> g;
    vector<int> p;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        g.push_back(str);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        p.push_back(tmp);
    }

    vector<int> ans = solution(g, p);

    for (int i : ans)
        cout << i << ' ';
}