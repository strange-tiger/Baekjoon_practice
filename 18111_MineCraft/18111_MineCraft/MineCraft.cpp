#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

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

	bool finished = false;
	while (!finished)
	{
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				if (map[0][0] != map[r][c])
				{
					finished = false;
				}
			}
		}
	}
}