#include <stdio.h>

int N, M;
int i, j;
int sum[100001] = { 0, };

int main()
{
	scanf("%d %d", &N, &M);

	for (int k = 1; k <= N; ++k)
	{
		scanf("%d", &sum[k]);
		sum[k] += sum[k - 1];
	}

	while (M--)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}

	return 0;
}