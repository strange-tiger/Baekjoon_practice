#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int N, M;
int answer = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cheese[MAX][MAX];
int melt[MAX][MAX] = { 0 };
bool isVisited[MAX][MAX] = { false };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> cheese[i][j];
}

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (isVisited[y][x])
			continue;
		isVisited[y][x] = true;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (cheese[ny][nx] == 1)
				++melt[ny][nx];
			else if (!isVisited[ny][nx])
				q.push({ nx, ny });
		}	
	}

	return;
}

bool Melt()
{
	bool isMelted = false;

	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j < M - 1; ++j)
		{
			if (melt[i][j] > 1)
			{
				cheese[i][j] = 0;
				isMelted = true;
			}
		}
	}

	return isMelted;
}

void solve()
{
	while (true)
	{
		memset(isVisited, false, sizeof(isVisited));
		memset(melt, 0, sizeof(melt));

		bfs();
		if (Melt())
			++answer;
		else
			break;
	}

	cout << answer;
}

int main()
{
	input();

	solve();

	return 0;
}