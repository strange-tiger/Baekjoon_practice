#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define min(x, y) x < y ? x : y

int n, i, j;
int dp[50005] = { 0 };
int main()
{
	scanf("%d", &n);

	for (i = 1; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		for (j = 1; j * j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[n]);

	return 0;
}