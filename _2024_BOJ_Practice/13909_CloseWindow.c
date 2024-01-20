#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, cnt = 0;
int main()
{
	scanf("%d", &N);

	for (int i = 1; i * i <= N; ++i)
		++cnt;

	printf("%d", cnt);

	return 0;
}