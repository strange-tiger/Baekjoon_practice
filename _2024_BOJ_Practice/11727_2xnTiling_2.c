#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define LIMIT 10007

int n;
int dp[1000] = { 0 };

int fibo(int num)
{
	if (dp[num - 1] || num < 3)
		return dp[num - 1];

	dp[num - 1] = 2 * fibo(num - 2) + fibo(num - 1);

	dp[num - 1] %= LIMIT;

	return dp[num - 1];
}

int main()
{
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 3;

	printf("%d", fibo(n));

	return 0;
}