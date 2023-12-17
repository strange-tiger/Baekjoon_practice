#include <iostream>
#include <string>
#include <queue>
using namespace std;

int D(int num)
{
    return (num * 2) % 10000;
}
int S(int num)
{
    return num - 1 < 0 ? 9999 : num - 1;
}
int L(int num)
{
    return (num % 1000) * 10 + num / 1000;
}
int R(int num)
{
    return num / 10 + (num % 10) * 1000;
}

int d, s, l, r;
string bfs(int a, int b)
{
    bool isVisited[10000] = { false };

    queue<pair<int, string>> q;
    q.push({ a, "" });
    isVisited[a] = true;
    
    while (!q.empty())
    {
        int num = q.front().first;
        string order = q.front().second;
        q.pop();

        if (num == b)
        {
            return order;
        }

        d = D(num);
        s = S(num);
        l = L(num);
        r = R(num);

        if (!isVisited[d])
        {
            q.push({ d, order + 'D' });
            isVisited[d] = true;
        }
        if (!isVisited[l])
        {
            q.push({ l, order + 'L' });
            isVisited[l] = true;
        }
        if (!isVisited[s])
        {
            q.push({ s, order + 'S' });
            isVisited[s] = true;
        }
        if (!isVisited[r])
        {
            q.push({ r, order + 'R' });
            isVisited[r] = true;
        }
    }
}

int T, A, B;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> A >> B;

        cout << bfs(A, B) << '\n';
    }

    return 0;
}