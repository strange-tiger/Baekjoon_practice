#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int T, C;
int quarter, dime, nickel, penny;
int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &C);

		quarter = C / 25;
		C %= 25;
		dime = C / 10;
		C %= 10;
		nickel = C / 5;
		penny = C % 5;
		
		printf("%d %d %d %d\n", quarter, dime, nickel, penny);
	}

	return 0;
}