#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int main(void)
{
	int N;
	scanf("%d", &N);

	int A[100000] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	std::sort(A, A + N);

	int M;
	scanf("%d", &M);

	int B[100000] = { 0 };
	for (int i = 0; i < M; i++)
	{
		int isExist = 0;
		scanf("%d", &B[i]);

		if (B[i] > A[N / 2])
		{
			for (int j = N / 2; j < N; j++)
			{
				if (B[i] == A[j])
				{
					isExist = 1;
					break;
				}
			}
		}

		if (B[i] < A[N / 2])
		{
			for (int j = N / 2 ; j >= 0; j--)
			{
				if (B[i] == A[j])
				{
					isExist = 1;
					break;
				}
			}
		}

		if (B[i] == A[N / 2])
		{
			isExist = 1;
		}

		printf("%d\n", isExist);
	}

	return 0;
}