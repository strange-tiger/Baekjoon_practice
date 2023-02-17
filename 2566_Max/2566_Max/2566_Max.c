#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int grid[9][9];
int max = 0;
int row, column;
int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			scanf("%d", &grid[i][j]);
			
			if (max <= grid[i][j])
			{
				max = grid[i][j];

				row = i + 1;
				column = j + 1;
			}
		}
	}

	printf("%d\n%d %d", max, row, column);

	return 0;
}