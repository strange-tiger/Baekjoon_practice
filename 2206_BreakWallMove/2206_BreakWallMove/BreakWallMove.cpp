#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int map[1001][1001] = { 0 };
int cnt[1001][1001] = { 0 };
queue<pair<int, int>> isBreakable;

int N, M;
int bfs()
{
	int min = 1'000'001;
	while (!isBreakable.empty())
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cnt[i][j] = 0;
			}
		}

		map[isBreakable.front().first][isBreakable.front().second] = 0;

		static int dr[4] = { 0, 0, 1, -1 };
		static int dc[4] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;
		q.push({ 1, 1 });
		cnt[1][1] = 1;

		while (!q.empty())
		{
			pair<int, int> ver = q.front();
			q.pop();
			int r = ver.first;
			int c = ver.second;

			if (r == N && c == M)
			{
				map[isBreakable.front().first][isBreakable.front().second] = 1;
				isBreakable.pop();

				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 1 || nr > N || nc < 1 || nc > M || cnt[nr][nc] != 0 || map[nr][nc] == 1)
				{
					continue;
				}

				q.push({ nr, nc });
				cnt[nr][nc] = cnt[r][c] + 1;
			}
		}

		if (cnt[N][M] != 0)
		{
			if (min > cnt[N][M])
			{
				min = cnt[N][M];
			}
		}
		else
		{
			map[isBreakable.front().first][isBreakable.front().second] = 1;
			isBreakable.pop();
		}
	}

	return min;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (map[i][j] == 1)
			{
				isBreakable.push({ i, j });
			}
		}
	}
	
	int min = bfs();

	if (min == 1'000'001)
	{
		min = -1;
	}

	printf("%d", min);

	return 0;
}