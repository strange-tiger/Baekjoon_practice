#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int K;
int A[46], B[46];
int main()
{
	scanf("%d", &K);

	A[0] = 1;
	B[0] = 0;
	A[1] = 0;
	B[1] = 1;

	for (int i = 2; i <= 45; ++i)
	{
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}

	printf("%d %d", A[K], B[K]);

	return 0;
}