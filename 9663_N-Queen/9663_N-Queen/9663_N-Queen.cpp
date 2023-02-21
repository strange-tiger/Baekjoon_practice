#include <iostream>
using namespace std;

int N, cnt;
int board[15] = { 0 };
bool check(int queen)
{
	for (int i = 0; i < queen; ++i)
	{
		if (board[queen] == board[i])
			return false;

		if (queen - i == board[queen] - board[i])
			return false;

		if (queen - i == board[i] - board[queen])
			return false;
	}

	return true;
}

void placement(int queen)
{
	if (queen == N)
	{
		++cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		board[queen] = i;

		if (check(queen))
		{
			placement(queen + 1);
		}
	}
}

int main(void)
{
	cin >> N;

	placement(0);

	cout << cnt;

	return 0;
}