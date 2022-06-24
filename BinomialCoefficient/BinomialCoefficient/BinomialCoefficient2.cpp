#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int* PT;
int K, N;
int main()
{
	scanf("%d %d", &N, &K);

	PT = new int[(N + 1) * (N + 2) / 2];

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			if (j == 0 || j == i)
			{
				PT[i * (i + 1) / 2 + j] = 1;
				continue;
			}

			PT[i * (i + 1) / 2 + j] = PT[(i - 1) * i / 2 + j - 1] + PT[(i - 1) * i / 2 + j];
			PT[i * (i + 1) / 2 + j] %= 10007;
		}
	}
	
	int result = PT[N * (N + 1) / 2 + K];

	printf("%d", result % 10007);

	delete[] PT;

	return 0;
}