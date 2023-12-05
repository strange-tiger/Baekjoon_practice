#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int A, B, C;

long long int multiply(long long int x)
{
	if (x == 1)
		return A % C;

	long long int interlude = multiply(x / 2) % C;

	interlude = interlude * interlude % C;

	if (x % 2 == 0)
		return interlude;
	else
		return interlude * A % C;
}

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	printf("%lld", multiply(B));

	return 0;
}