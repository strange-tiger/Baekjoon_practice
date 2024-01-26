#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N, K, Sum, i;
int Max = -10000001;
int sum[100004] = { 0 };
int main()
{
	scanf("%d %d", &N, &K);
	
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", sum + i);
		sum[i] += sum[i - 1];
	}

	for (i = K; i <= N; ++i)
	{
		Sum = sum[i] - sum[i - K];

		if (Max < Sum)
			Max = Sum;
	}

	printf("%d", Max);

	return 0;
}