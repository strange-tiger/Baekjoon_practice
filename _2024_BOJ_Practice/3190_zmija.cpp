#include <iostream>
#include <queue>
using namespace std;

int N, K, L, ans = 0;
int dir = 0;
bool flag = true;
pair<int, int> head = { 0, 0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool board[100][100] = { false };
deque<pair<int, int>> snake;
queue<pair<int, char>> turn;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> K;

	int r, c;
	for (int i = 0; i < K; ++i)
	{
		cin >> r >> c;
		board[r - 1][c - 1] = true;
	}

	cin >> L;
	int t;
	char d;
	for (int i = 0; i < L; ++i)
	{
		cin >> t >> d;
		turn.push({ t, d });
	}
}

void solve()
{
	snake.push_front(head);
	while (flag)
	{
		++ans;

		head.first += dx[dir];
		head.second += dy[dir];

		if (head.first < 0 || head.first >= N || head.second < 0 || head.second >= N)
		{
			flag = false;
			break;
		}

		for (pair<int, int> body : snake)
		{
			if (head.first == body.first && head.second == body.second)
			{
				flag = false;
				break;
			}
		}

		snake.push_front(head);

		if (board[head.second][head.first])
			board[head.second][head.first] = false;
		else
			snake.pop_back();

		if (!turn.empty() && ans == turn.front().first)
		{
			if (turn.front().second == 'L')
				dir = (dir + 1) % 4;
			else if (turn.front().second == 'D')
				dir = (dir + 3) % 4;
			turn.pop();
		}
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}