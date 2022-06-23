#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);

	int A[50] = { 0 };
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &A[i]);
	}

	int minA = 1000001;
	int maxA = 0;
	
	for (int i = 0; i < num; i++)
	{
		if (minA > A[i])
		{
			minA = A[i];
		}

		if (maxA < A[i])
		{
			maxA = A[i];
		}
	}

	printf("%d", minA * maxA);
}