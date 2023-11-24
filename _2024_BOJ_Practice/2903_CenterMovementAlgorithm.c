#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N;
int side = 1;
int main()
{
	scanf("%d", &N);

	while (N--)
		side *= 2;
	++side;

	printf("%d", side * side);

	return 0;
}