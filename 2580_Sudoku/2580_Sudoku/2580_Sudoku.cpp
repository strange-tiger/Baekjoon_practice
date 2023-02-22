#include <iostream>
using namespace std;

int board[9][9];
bool row[9][9] = { false };
bool column[9][9] = { false };
bool box[9][9] = { false };

int setBoxIndex(int x, int y)
{
	return x / 3 + 3 * (y / 3);
}

void setProbability(int x, int y, int index, bool set)
{
	--index;
	row[y][index] = set;
	column[x][index] = set;
	box[setBoxIndex(x, y)][index] = set;
}

bool check(int x, int y, int num)
{
	if (row[y][num - 1])
		return false;
	if (column[x][num - 1])
		return false;
	if (box[setBoxIndex(x, y)][num - 1])
		return false;

	return true;
}

bool sudoku(int num)
{
	if (num > 80)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		return true;
	}

	int x = num % 9;
	int y = num / 9;

	if (board[y][x] != 0)
		return sudoku(num + 1);

	for (int i = 1; i <= 9; ++i)
	{
		if (check(x, y, i))
		{
			board[y][x] = i;
			setProbability(x, y, i, true);

			if (sudoku(num + 1))
				return true;

			board[y][x] = 0;
			setProbability(x, y, i, false);
		}
	}

	return false;
}

int main(void)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] != 0)
				setProbability(j, i, board[i][j], true);
		}
	}

	sudoku(0);

	return 0;
}