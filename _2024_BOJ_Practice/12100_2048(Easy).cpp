#include <iostream>
#include <queue>
#define MAX 20
using namespace std;

int N, Max = 0;
int board[MAX][MAX];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
}

void shift(int direction)
{
	queue<int> q;

	switch (direction)
	{
	case 0:
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = 0;
			int data;

			while (!q.empty())
			{
				data = q.front();
				q.pop();

				if (board[i][idx] == 0)
					board[i][idx] = data;
				else if (board[i][idx] == data)
				{
					board[i][idx] += data;
					++idx;
				}
				else
				{
					++idx;
					board[i][idx] = data;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < N; ++i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}

			int idx = N - 1;
			int data;

			while (!q.empty())
			{
				data = q.front();
				q.pop();

				if (board[i][idx] == 0)
					board[i][idx] = data;
				else if (board[i][idx] == data)
				{
					board[i][idx] += data;
					--idx;
				}
				else
				{
					--idx;
					board[i][idx] = data;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[j][i])
					q.push(board[j][i]);
				board[j][i] = 0;
			}

			int idx = 0;
			int data;

			while (!q.empty())
			{
				data = q.front();
				q.pop();

				if (board[idx][i] == 0)
					board[idx][i] = data;
				else if (board[idx][i] == data)
				{
					board[idx][i] += data;
					++idx;
				}
				else
				{
					++idx;
					board[idx][i] = data;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < N; ++i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (board[j][i])
					q.push(board[j][i]);
				board[j][i] = 0;
			}

			int idx = N - 1;
			int data;

			while (!q.empty())
			{
				data = q.front();
				q.pop();

				if (board[idx][i] == 0)
					board[idx][i] = data;
				else if (board[idx][i] == data)
				{
					board[idx][i] += data;
					--idx;
				}
				else
				{
					--idx;
					board[idx][i] = data;
				}
			}
		}
		break;
	}
}

void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				Max = max(Max, board[i][j]);
		return;
	}

	int befBoard[MAX][MAX];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			befBoard[i][j] = board[i][j];

	for (int i = 0; i < 4; ++i)
	{
		shift(i);
		dfs(cnt + 1);
		
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j] = befBoard[i][j];
	}
}

void solve()
{
	dfs(0);
	cout << Max;
}

int main()
{
	input();
	solve();
	return 0;
}