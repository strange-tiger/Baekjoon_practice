#include <iostream>
using namespace std;

int N, M, answer;
int arr[102][102] = { 0 };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    answer = 2 * N * M;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> arr[i][j];
}

void compare(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[y][x] > arr[ny][nx])
            answer += (arr[y][x] - arr[ny][nx]);
    }
}

void solve()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            compare(j, i);

    cout << answer;
}

int main()
{
    input();
    solve();
    return 0;
}