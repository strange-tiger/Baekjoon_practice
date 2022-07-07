#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int N, M;
int main()
{
	scanf("%d %d", &N, &M);
	
	printf("%d", M - gcd(N, M));

	return 0;
}