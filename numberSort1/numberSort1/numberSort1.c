#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int num[1000];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", num + i);
	}

	for (int j = N; j > 1; j--)
	{
		for (int i = 1; i < j; i++)
		{
			if (num[i - 1] > num[i])
			{
				int temp;
				temp = num[i - 1];
				num[i - 1] = num[i];
				num[i] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", num[i]);
	}
}