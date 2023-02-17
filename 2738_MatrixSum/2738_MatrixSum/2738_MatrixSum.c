#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int sum[100][100];
int main(void)
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &sum[i][j]);

	int tmp;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &tmp);

			sum[i][j] += tmp;
		}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}

	return 0;
}