#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> q;
void bfs()
{
	static int dx[] = { 1, 0, -1, 0 };
	static int dy[] = { 0, 1, 0, -1 };

	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1 || map[nx][ny] == 0)
				continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 1000; ++i)
	{
		memset(map[i], 0, 1000 * sizeof(int));
		memset(dist[i], -1, 1000 * sizeof(int));
	}

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
			{
				dist[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	bfs();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (map[i][j] == 0)
				cout << 0 << ' ';
			else
				cout << dist[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}