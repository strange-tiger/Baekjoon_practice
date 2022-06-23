#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//long long Factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return (long long)(n * Factorial(n - 1));
//	}
//}

//long long Factorial(int n, int r)
//{
//	if (n <= r)
//	{
//		return 1;
//	}
//	else
//	{
//		return (long long)(n * Factorial(n - 1, r));
//	}
//}

int Combination(int n, int r)
{
	if (n <= r)
	{
		return 1;
	}
	else
	{
		return n * Combination(n - 1, r) / (n - r);
	}
}

int T, N, M;
int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &M);

		int result;
		
		result = Combination(M, N);

		printf("%d\n", result);
	}

	return 0;
}