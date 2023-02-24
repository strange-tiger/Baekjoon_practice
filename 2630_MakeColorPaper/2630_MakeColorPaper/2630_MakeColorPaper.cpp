#include <iostream>
using namespace std;

int N;
int white = 0, blue = 0;
bool paper[128][128] = { false };
int divide(int x, int y, int n)
{
	if (n == 1)
		return paper[y][x];

	int half = n / 2;

	if ((divide(x, y, half) == 1)
		&& (divide(x + half, y, half) == 1)
		&& (divide(x, y + half, half) == 1)
		&& (divide(x + half, y + half, half) == 1))
	{
		blue -= 3;
		return 1;
	}

	if ((divide(x, y, half) == 0)
		&& (divide(x + half, y, half) == 0)
		&& (divide(x, y + half, half) == 0)
		&& (divide(x + half, y + half, half) == 0))
	{
		white -= 3;
		return 0;
	}

	return -1;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> paper[i][j];

			if (paper[i][j])
				++blue;
			else
				++white;
		}
	}

	divide(0, 0, N);

	cout << white << '\n' << blue;

	return 0;
}