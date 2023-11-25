#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N, K;
int div = 0;
int main()
{
	scanf("%d %d", &N, &K);

	while (K)
	{
		++div;
		
		if (N % div == 0)
		{
			--K;
		}
		else if (N < div)
		{
			K = 0;
			div = 0;
		}
	}

	printf("%d", div);

	return 0;
}