#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int A, B, C;
long long interlude[32];
long long result = 0;
int main()
{
	scanf("%d %d %d", &A, &B, &C);

	interlude[0] = A % C;

	int cnt = 1;
	int i = 1;
	for (i; cnt < B / 2; ++i)
	{
		cnt *= 2;
		interlude[i] = interlude[i - 1] * interlude[i - 1] % C;
	}

	result = interlude[i - 1];

	B = B - cnt;

	while (B > 0)
	{
		for (i = 0, cnt = 1; cnt < B; ++i)
			cnt *= 2;

		result = result * interlude[i] % C;

		B = B - cnt;
	}

	printf("%lld", result);

	return 0;
}