#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int N, W, H;
	scanf("%d %d %d", &N, &W, &H);

	int num[50];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", num + i);

		if (num[i] * num[i] <= W * W + H * H)
		{
			printf("DA\n");
		}
		else
		{
			printf("NE\n");
		}
	}
}