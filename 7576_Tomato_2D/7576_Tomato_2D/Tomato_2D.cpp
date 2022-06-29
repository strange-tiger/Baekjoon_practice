#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

int M, N, K;
bool isVisited[1000][1000];
int box[1000][1000];
int count[1000][1000];

int bfs()
{
	static int dy[] = { -1, 0, 1, 0 };
	static int dx[] = { 0, 1, 0, -1 };

	std::queue<std::pair<int, int>> ripe;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			if (1 == box[i][j] && !isVisited[i][j])
			{
				ripe.push({ i, j });
				isVisited[i][j] = true;
				count[i][j] = 0;
			}
	}

	int max = 0;
	while (!ripe.empty())
	{
		int ver_y = ripe.front().first;
		int ver_x = ripe.front().second;
		ripe.pop();

		if (max < count[ver_y][ver_x])
		{
			max = count[ver_y][ver_x];
		}

		for (int i = 0; i < 4; ++i)
		{
			int nVer_y = ver_y + dy[i];
			int nVer_x = ver_x + dx[i];

			if (nVer_y < 0 || nVer_y >= N || nVer_x < 0 || nVer_x >= M)
				continue;

			if (!isVisited[nVer_y][nVer_x])
			{
				if (0 == box[nVer_y][nVer_x])
				{
					ripe.push({ nVer_y, nVer_x });
					isVisited[nVer_y][nVer_x] = true;
					box[nVer_y][nVer_x] = 1;

					count[nVer_y][nVer_x] = count[ver_y][ver_x] + 1;
				}
			}
		}
	}

	return max;
}

int main()
{
	for (int i = 0; i < 1000; ++i)
	{
		std::memset(isVisited[i], 0, 1000 * sizeof(bool));
		std::memset(box[i], 0, 1000 * sizeof(int));
		std::memset(count[i], 0, 1000 * sizeof(int));
	}

	scanf("%d %d", &M, &N);

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			scanf("%d", &box[r][c]);

			if (-1 == box[r][c])
			{
				isVisited[r][c] = true;
			}
		}
	}

	int max = 0;
	max = bfs();

	bool able = true;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < M; ++c)
		{
			if (!isVisited[r][c])
			{
				able = false;
			}
		}
	}
	
	if (able)
		printf("%d\n", max);
	else
		printf("-1\n");

	return 0;
}