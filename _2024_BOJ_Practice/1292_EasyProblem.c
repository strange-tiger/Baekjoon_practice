#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int A, B;
int sum[1001] = { 0 };
int main()
{
	scanf("%d %d", &A, &B);

	int cnt = 0;
	sum[cnt] = 0;
	for (int i = 1; i <= 44; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			++cnt;
			sum[cnt] = sum[cnt - 1] + i;
		}
	}

	while (cnt < 1000)
	{
		++cnt;
		sum[cnt] = sum[cnt - 1] + 45;
	}

	printf("%d", sum[B] - sum[A - 1]);

	return 0;
}