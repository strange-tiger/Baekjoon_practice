#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int T, M = 0, N = 0, K, ans = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int cabbage[50][50] = { 0 };
bool isVisited[50][50] = { 0 };

void dfs(int x, int y)
{
	stack<pair<int, int>> s;
	s.push({ x, y });
	isVisited[y][x] = true;

	while (!s.empty())
	{
		bool notEnd = false;

		for (int i = 0; i < 4; ++i)
		{
			x = s.top().first;
			y = s.top().second;

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (cabbage[ny][nx] == 1 && !isVisited[ny][nx])
				{
					s.push({ nx, ny });
					isVisited[ny][nx] = true;
					notEnd = true;
				}
			}
		}

		if (!notEnd)
			s.pop();
	}
}

void init()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cabbage[i][j] = 0;
			isVisited[i][j] = false;
		}
	}

	ans = 0;
}

void input()
{
	init();

	cin >> M >> N >> K;

	int x, y;
	for (int i = 0; i < K; ++i)
	{
		cin >> x >> y;
		cabbage[y][x] = 1;
	}
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (cabbage[i][j] == 1 && !isVisited[i][j])
			{
				++ans;
				dfs(j, i);
			}
		}
	}

	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		input();
		solve();
	}

	return 0;
}