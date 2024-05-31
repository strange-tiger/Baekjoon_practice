#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int sum[2001][2001] = { 0 };
char board[2001][2001];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
}

int minRepaint(char color)
{
	int MIN = 2e6;
	int change, cnt;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if ((i + j) % 2 == 0)
				change = board[i][j] != color;
			else
				change = board[i][j] == color;
			
			sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + change;
		}
	}

	for (int i = 0; i <= N - K; ++i)
	{
		for (int j = 0; j <= M - K; ++j)
		{
			cnt = sum[i + K][j + K] - sum[i + K][j] - sum[i][j + K] + sum[i][j];

			MIN = min(MIN, cnt);
		}
	}

	return MIN;
}

void solve()
{
	cout << min(minRepaint('B'),minRepaint('W'));
}

int main()
{
	input();
	solve();
	return 0;
}