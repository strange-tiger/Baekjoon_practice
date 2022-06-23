#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int cnt = 0;
	int movieNum = 0;

	while (cnt != N)
	{
		movieNum++;
		if (movieNum % 1000 == 666 || movieNum / 10 % 1000 == 666 || movieNum / 100 % 1000 == 666 || movieNum / 1000 % 1000 == 666)
		{
			cnt++;
		}
	}

	printf("%d", movieNum);
}