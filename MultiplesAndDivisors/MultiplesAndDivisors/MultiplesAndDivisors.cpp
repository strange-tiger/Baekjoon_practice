#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = -1;
	int num2 = -1;
	while (scanf("%d %d", &num1, &num2), num1 != 0 || num2 != 0)
	{
		if (num1 / num2 != 0 && num1 % num2 == 0)
		{
			printf("multiple\n");
		}
		else if (num2 / num1 != 0 && num2 % num1 == 0)
		{
			printf("factor\n");
		}
		else
		{
			printf("neither\n");
		}
	}
}