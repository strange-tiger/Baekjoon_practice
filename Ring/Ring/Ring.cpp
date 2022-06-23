#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int gcd(int a, int b)
{
	int less, more;

	if (a > b)
	{
		less = b;
		more = a;
	}
	else
	{
		less = a;
		more = b;
	}

	while (1)
	{
		if (!(more % less))
		{
			break;
		}
		more = more % less;

		int temp;
		temp = more;
		more = less;
		less = temp;
	}

	return less;
}

int N;
int ring[100];
int GCD[99];
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &ring[i]);
	}

	for (int i = 1; i < N; ++i)
	{
		GCD[i - 1] = gcd(ring[0], ring[i]);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		printf("%d/%d\n", ring[0] / GCD[i], ring[i + 1] / GCD[i]);
	}

	return 0;
}