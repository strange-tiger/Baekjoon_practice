#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N, A[1000];
int dp[1000];
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}

	int maxCnt = 0;
	int max = 0;
	int cnt = 0;
	for (int j = 0; j < N - maxCnt; ++j)
	{
		for (int i = j; i < N; ++i)
		{
			if (max < A[i])
			{
				max = A[i];
				++cnt;
			}
		}
		if (maxCnt < cnt)
		{
			maxCnt = cnt;
		}
	}
	printf("%d", cnt);
}