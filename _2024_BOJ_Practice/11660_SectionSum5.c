#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int x1, y1, x2, y2;
int result;
int sum[1024][1025] = { 0 };
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			scanf("%d", &sum[i][j]);
			sum[i][j] += sum[i][j - 1];
		}
	}

	while (M--)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		result = 0;
		for (int i = x1 - 1; i < x2; ++i)
			result += sum[i][y2] - sum[i][y1 - 1];

		printf("%d\n", result);
	}

	return 0;
}