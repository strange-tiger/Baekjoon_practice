#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, b, c;
int main()
{
	scanf("%d %d %d", &a, &b, &c);

	if (a >= b + c)
		printf("%d", 2 * (b + c) - 1);
	else if (b >= a + c)
		printf("%d", 2 * (a + c) - 1);
	else if (c >= b + a)
		printf("%d", 2 * (b + a) - 1);
	else
		printf("%d", a + b + c);

	return 0;
}