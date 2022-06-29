#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

int M, N, H;
bool isVisited[100][100][100];
int box[100][100][100];
int count[100][100][100];

int bfs()
{
	static int dz[] = { 0, 0, 1, 0, 0, -1 };
	static int dy[] = { 0, 1, 0, 0, -1, 0 };
	static int dx[] = { 1, 0, 0, -1, 0, 0 };

	std::queue<std::pair<int, std::pair<int, int>>> ripe;
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (1 == box[k][i][j] && !isVisited[k][i][j])
				{
					ripe.push({ k, { i, j } });
					isVisited[k][i][j] = true;
					count[k][i][j] = 0;
				}
			}
		}
	}

	int max = 0;
	while (!ripe.empty())
	{
		int ver_z = ripe.front().first;
		int ver_y = ripe.front().second.first;
		int ver_x = ripe.front().second.second;
		ripe.pop();

		if (max < count[ver_z][ver_y][ver_x])
		{
			max = count[ver_z][ver_y][ver_x];
		}

		for (int i = 0; i < 6; ++i)
		{
			int nVer_z = ver_z + dz[i];
			int nVer_y = ver_y + dy[i];
			int nVer_x = ver_x + dx[i];

			if (nVer_z < 0 || nVer_z >= H || nVer_y < 0 || nVer_y >= N || nVer_x < 0 || nVer_x >= M)
				continue;

			if (!isVisited[nVer_z][nVer_y][nVer_x])
			{
				if (0 == box[nVer_z][nVer_y][nVer_x])
				{
					ripe.push({ nVer_z, {nVer_y, nVer_x } });
					isVisited[nVer_z][nVer_y][nVer_x] = true;
					box[nVer_z][nVer_y][nVer_x] = 1;

					count[nVer_z][nVer_y][nVer_x] = count[ver_z][ver_y][ver_x] + 1;
				}
			}
		}
	}

	return max;
}

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			std::memset(isVisited[i][j], 0, 100 * sizeof(bool));
			std::memset(box[i][j], 0, 100 * sizeof(int));
			std::memset(count[i][j], 0, 100 * sizeof(int));
		}
	}

	scanf("%d %d %d", &M, &N, &H);
	
	for (int h = 0; h < H; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				scanf("%d", &box[h][r][c]);

				if (-1 == box[h][r][c])
				{
					isVisited[h][r][c] = true;
				}
			}
		}
	}

	int max = 0;
	max = bfs();

	bool able = true;
	for (int h = 0; h < H; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (!isVisited[h][r][c])
				{
					able = false;
				}
			}
		}
	}

	if (able)
		printf("%d\n", max);
	else
		printf("-1\n");

	return 0;
}