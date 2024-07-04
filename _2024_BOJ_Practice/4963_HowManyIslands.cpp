#include <iostream>
#include <queue>
using namespace std;

int w, h;
int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1};
int map[50][50];
bool isVisited[50][50];

void init()
{
	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			map[i][j] = 0;
			isVisited[i][j] = false;
		}
	}
}

void input()
{
	init();

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			cin >> map[i][j];
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	isVisited[y][x] = true;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		int nx, ny;
		for (int i = 0; i < 8; ++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < w && ny < h)
			{
				if (map[ny][nx] == 1 && !isVisited[ny][nx])
				{
					isVisited[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}

void solve()
{
	int ans = 0;

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (map[i][j] == 1 && !isVisited[i][j])
			{
				++ans;
				bfs(j, i);
			}
		}
	}

	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> w >> h, w != 0 && h != 0)
	{
		input();
		solve();
	}

	return 0;
}