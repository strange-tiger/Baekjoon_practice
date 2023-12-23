#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int seq[8];
bool visit[8];
void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < N; ++i)
    {
        if (!visit[i] && num[i] != temp)
        {
            seq[depth] = num[i];
            temp = seq[depth];
            visit[i] = true;

            dfs(depth + 1);

            visit[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> num[i];
    }

    sort(num, num + N);

    dfs(0);

    return 0;
}