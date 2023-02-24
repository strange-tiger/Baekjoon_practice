#include <iostream>
using namespace std;

int N;
int white = 0, blue = 0;
bool paper[128][128] = { false };
void divide(int x, int y, int n)
{
	int tmp = 0;

	for (int i = y; i < y + n; ++i)
		for (int j = x; j < x + n; ++j)
			if (paper[i][j])
				++tmp;

	if (tmp == 0)
		++white;
	else if (tmp == n * n)
		++blue;
	else
	{
		int half = n / 2;

		divide(x, y, half);
		divide(x + half, y, half);
		divide(x, y + half, half);
		divide(x + half, y + half, half);
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];

	divide(0, 0, N);

	cout << white << '\n' << blue;

	return 0;
}