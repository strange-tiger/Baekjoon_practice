#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

long long int A, B, C;
long long int result = 1;
int main()
{
	scanf("%lld %lld %lld", &A, &B, &C);

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			result *= A;
			result %= C;
		}
		B /= 2;
		A *= A;
		A %= C;
	}

	printf("%lld", result);

	return 0;
}