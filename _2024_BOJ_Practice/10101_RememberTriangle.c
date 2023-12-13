#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, b, c, sum;
int main()
{
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	sum = a + b + c;

	if (sum != 180)
		printf("Error");
	else if (a == b && b == c)
		printf("Equilateral");
	else if (a == b || b == c || a == c)
		printf("Isosceles");
	else
		printf("Scalene");

	return 0;
}