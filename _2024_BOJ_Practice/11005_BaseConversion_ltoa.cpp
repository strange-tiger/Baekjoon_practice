#include <cstdio>
#include <cstdlib>

int N;
int B;
char result[30];

int main()
{
	scanf("%d %d", &N, &B);
	printf("%s", _ltoa(N, result, B));
}