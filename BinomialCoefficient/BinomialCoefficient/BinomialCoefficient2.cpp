#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int Combination2(int n, int r)
{
	if (n <= r)
	{
		return 1;
	}
	else if (Combination2(n - 1, r) % 10007 == 0)
	{
		return n * (Combination2(n - 1, r) / 10007) / (n - r);
	}
	else
	{
		return n * Combination2(n - 1, r) / (n - r);
	}
}

int K, N;
int main()
{

	scanf("%d %d", &N, &K);

	int result = 1;

	result = Combination2(N, K);
	
	result %= 10007;

	printf("%d\n", result);

	return 0;
}