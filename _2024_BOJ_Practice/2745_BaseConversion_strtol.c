#include <stdio.h>
#include <stdlib.h>

char N[30];
int B = 0;

int main()
{
	scanf("%s %d", N, &B);
	printf("%d", strtol(N, NULL, B));

	return 0;
}