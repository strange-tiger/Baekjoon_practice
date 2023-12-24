#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int seq[8];
void dfs(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (depth == 0 || num[i] >= seq[depth - 1])
        {
            seq[depth] = num[i];
            dfs(depth + 1);
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