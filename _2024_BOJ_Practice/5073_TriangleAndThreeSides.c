#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, b, c;
int main()
{
	while (scanf("%d %d %d", &a, &b, &c), a != 0 && b != 0 && c != 0)
	{
		if (a >= b + c || b >= a + c || c >= a + b)
			printf("Invalid\n");
		else if (a == b && b == c)
			printf("Equilateral\n");
		else if (a == b || b == c|| a == c)
			printf("Isosceles\n");
		else
			printf("Scalene\n");
	}

	return 0;
}