#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int seq[8];
void dfs(int x, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; ++i)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = x; i < N; ++i)
    {
        seq[depth] = num[i];
        dfs(i, depth + 1);
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

    dfs(0, 0);

    return 0;
}