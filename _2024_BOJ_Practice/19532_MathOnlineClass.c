#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, b, c, d, e, f, x, y;
int main()
{
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	x = (c * e - b * f) / (a * e - b * d);
	y = (c * d - a * f) / (b * d - a * e);

	printf("%d %d", x, y);
	return 0;
}