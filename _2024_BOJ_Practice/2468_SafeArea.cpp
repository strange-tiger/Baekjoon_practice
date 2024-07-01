#include <iostream>
using namespace std;

int N, ans = 0;
int area[100][100];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool isVisited[100][100] = { false };

void dfs(int x, int y, int height)
{
	isVisited[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		{
			if (area[ny][nx] > height && !isVisited[ny][nx])
			{
				dfs(nx, ny, height);
			}
		}
	}
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> area[i][j];
}

void init()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			isVisited[i][j] = false;
}

void solve()
{
	for (int h = 0; h < 101; ++h)
	{
		init();

		int safe = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (area[i][j] > h && !isVisited[i][j])
				{
					++safe;
					dfs(j, i, h);
				}
			}
		}

		if (ans < safe)
			ans = safe;
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}