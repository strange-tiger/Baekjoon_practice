#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a1, a0, c, n0;
int main()
{
	scanf("%d %d %d %d", &a1, &a0, &c, &n0);

	if (a1 * n0 + a0 <= c * n0 && a1 <= c)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}