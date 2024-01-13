#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

long long int N;
long long int factorial(long long int num)
{
	if (num == 0)
		return 1;
	return num * factorial(num - 1);
}
int main()
{
	scanf("%lld", &N);
	printf("%lld", factorial(N));
	return 0;
}