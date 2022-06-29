#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define _INF 131072

int map[500][500] = { 0 };
bool smooth[500][500] = { false };

int N, M, B, time = 0;
int main()
{
	scanf("%d %d %d", &N, &M, &B);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int block[257] = { 0 };
	for (int h = 0; h <= 256; ++h)
	{
		block[h] = B;
	}

	int time[257] = { 0 };
	for (int h = 0; h <= 256; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (h < map[r][c])
				{
					int cnt = map[r][c];
					while (h < cnt)
					{
						time[h] += 2;
						++block[h];
						--cnt;
					}
				}
			}
		}
	}

	int lessTime = _INF;
	int maxHeight = 0;
	for (int h = 0; h <= 256; ++h)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (h > map[r][c])
				{
					int cnt = map[r][c];
					while (h > cnt)
					{
						if (block[h] > 0)
						{
							time[h] += 1;
							--block[h];
							++cnt;
						}
						else
						{
							time[h] = _INF;

							break;
						}
					}
				}
			}
		}

		if (lessTime > time[h])
		{
			lessTime = time[h];
			maxHeight = h;
		}
		else if (lessTime == time[h])
		{
			maxHeight = h;
		}
	}

	printf("%d %d", lessTime, maxHeight);

	return 0;
}