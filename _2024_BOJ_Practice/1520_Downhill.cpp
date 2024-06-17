#include <iostream>
#define MAX 500
using namespace std;

int M, N;
int map[MAX][MAX];
int dp[MAX][MAX] = { 0 };
bool isVisited[MAX][MAX] = { false };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			cin >> map[i][j];
}

int dfs(int x, int y)
{
	if (x == N - 1 && y == M - 1)
		return 1;
	if (isVisited[y][x])
		return dp[y][x];

	isVisited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[ny][nx] < map[y][x])
			dp[y][x] = dp[y][x] + dfs(nx, ny);
	}

	return dp[y][x];
}

void solve()
{
	cout << dfs(0, 0);
}

int main()
{
	input();
	solve();
	return 0;
}