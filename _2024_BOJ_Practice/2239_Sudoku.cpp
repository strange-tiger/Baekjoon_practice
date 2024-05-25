#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> blanks;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; ++i)
	{
		string str;
		cin >> str;

		for (int j = 0; j < 9; ++j)
		{
			sudoku[i][j] = str[j] - '0';

			if (sudoku[i][j] == 0)
				blanks.push_back({ i, j });
		}
	}
}

bool isSudoku(int x, int y, int k)
{
	for (int i = 0; i < 9; ++i)
	{
		if (sudoku[y][i] == k && i != x)
			return false;
		if (sudoku[i][x] == k && i != y)
			return false;

		int nx = x / 3 * 3 + i % 3;
		int ny = y / 3 * 3 + i / 3;
		if (sudoku[ny][nx] == k && (nx != x || ny != y))
			return false;
	}
	return true;
}

void backTrack(int num)
{
	if (num == blanks.size())
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				cout << sudoku[i][j];
			cout << '\n';
		}
		return;
	}

	int x = blanks[num].second;
	int y = blanks[num].first;

	for (int k = 1; k <= 9; ++k)
	{
		if (isSudoku(x, y, k))
		{
			sudoku[y][x] = k;
			backTrack(num + 1);
			sudoku[y][x] = 0;
		}
	}
}

void solve()
{
	backTrack(0);
}

int main()
{
	input();
	solve();
	return 0;
}