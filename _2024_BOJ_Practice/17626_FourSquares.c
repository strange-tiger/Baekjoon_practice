#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int n, big, cnt = 0;
int main()
{
	scanf("%d", &n);

	big = (int)sqrt(n);
	n -= big * big;
	++cnt;

	for (int i = big; i > 0; --i)
	{
		if (n >= i * i)
		{
			n -= i * i;
			++cnt;
		}
	}

	printf("%d", cnt);

	return 0;
}