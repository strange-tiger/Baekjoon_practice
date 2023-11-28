#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N, x, y;
int xMax = -10001;
int xMin = 10001;
int yMax = -10001;
int yMin = 10001;
int main()
{
	scanf("%d", &N);

	while (N--)
	{
		scanf("%d %d", &x, &y);

		if (x > xMax)
			xMax = x;
		if (x < xMin)
			xMin = x;
		if (y > yMax)
			yMax = y;
		if (y < yMin)
			yMin = y;
	}

	printf("%d", (xMax - xMin) * (yMax - yMin));

	return 0;
}