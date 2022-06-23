#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int K;
	scanf("%d", &K);

	int dir[6] = { 0 };
	int length[6] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		scanf("%d %d", dir + i, length + i);
	}

	int dim1 = 0;
	int dim2 = 0;
	int cnt = 0;
	int width = 0;
	int height = 0;

	for (int i = 0; i < 6; i++)
	{
		int dim = 0;

		if (dir[i] == dir[i + 2])
		{
			dim = length[i + 1];
		}

		if (i == 0)
		{
			if (dir[i] == dir[i + 4])
			{
				dim = length[i + 5];
			}
		}

		if (i == 1)
		{
			if (dir[i] == dir[i + 4])
			{
				dim = length[i - 1];
			}
		}

		if (dir[i] <= 2 && length[i] > width)
		{
			width = length[i];
		}
		if (dir[i] > 2 && length[i] > height)
		{
			height = length[i];
		}

		if (cnt == 0 && dim != 0)
		{
			cnt++;
			dim1 = dim;
		}
		else if (cnt == 1 && dim != 0)
		{
			cnt++;
			dim2 = dim;
			// break;
		}
	}

	int area = width * height - dim1 * dim2;
	int result = area * K;

	printf("%d\n", result);
}