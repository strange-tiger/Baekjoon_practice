#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int A, B;
long long int less, more;
int main()
{
	scanf("%lld %lld", &A, &B);


	if (A > B)
	{
		less = B;
		more = A;
	}
	else
	{
		less = A;
		more = B;
	}

	while (1)
	{
		if (!(more % less))
		{
			break;
		}
		more = more % less;

		long long int temp;
		temp = more;
		more = less;
		less = temp;
	}

	printf("%lld\n", A * B / less);

	return 0;
}