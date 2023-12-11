// 이전 버전 반례
/*
100 1 65 1 정 : 65 답 : -1
60 15 20 5 정 : 20 답 : -1
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int T, M, N, x, y, ans;

int gcd(int a, int b) 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b) 
{
	return (a * b) / gcd(a, b);
}

int main()
{
	scanf("%d", &T);

	int i = 0;
	while (T--)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);

		ans = -1;

		int max = lcm(M, N);
		for (i = x; i <= max; i += M)
		{
			if (i % N == y % N)
			{
				ans = i;
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}