#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, div, cnt, sum;
int result[15] = { 0, };
int main()
{
	while (scanf("%d", &n), n != -1)
	{
		div = 1;
		cnt = 0;
		sum = 1;
		while (++div < n)
		{
			if (n % div == 0)
			{
				result[cnt] = div;
				sum += div;
				++cnt;
			}
		}

		if (n != sum)
		{
			printf("%d is NOT perfect.\n", n);
		}
		else
		{
			printf("%d = 1", n);

			for (int i = 0; i < cnt; ++i)
				printf(" + %d", result[i]);

			printf("\n");
		}
	}
}