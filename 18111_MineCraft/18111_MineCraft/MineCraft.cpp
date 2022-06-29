#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define _INF 64000000

int map[500][500] = { 0 };

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

	int leastTime = _INF;
	int maxHeight = 0;
	for (int h = 0; h <= 256; ++h)
	{
		int bld = 0;
		int dig = 0;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				int irreg = map[r][c] - h;

				if (irreg > 0)
					dig += irreg;
				else if (irreg < 0)
					bld -= irreg;
			}
		}

		if (dig + B >= bld)
		{
			int time = 2 * dig + bld;
			if (leastTime >= time)
			{
				leastTime = time;
				maxHeight = h;
			}
		}
	}

	printf("%d %d\n", leastTime, maxHeight);

	return 0;
}