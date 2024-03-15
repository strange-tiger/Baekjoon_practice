#include <iostream>
#include <utility>
#include <queue>
#define MAX 100
using namespace std;

int N, M;
int answer = 0;
int cheese[MAX][MAX];
int cnt[MAX][MAX];
int melt[MAX][MAX] = { 0 };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int checkEnd = 0;
bool remain = true;
queue<pair<int, int>> q;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> cheese[i][j];
}

void bfs()
{
	q.push({ 0, 0 });
	cnt[0][0] = 1;

	int x, y;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x == M - 1 && y == N - 1)
		{
			while (!q.empty())
				q.pop();
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (cheese[ny][nx] == 1)
				continue;

			q.push({ nx, ny });
			cnt[ny][nx] = cnt[y][x] + 1;
		}	
	}

	return;
}

void Melt()
{
	while (remain)
	{
		bfs();
	
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (cheese[i][j] == 1)
				{
					int limit = 0;

					for (int k = 0; k < 4; ++k)
					{
						int nj = j + dx[k];
						int ni = i + dy[k];

						if (nj < 0 || nj >= M || ni < 0 || ni >= N)
							continue;
						if (cheese[ni][nj] == 0 && cnt[ni][nj] != 0)
							++limit;
						
						if (limit > 1)
						{
							melt[i][j] = 1;
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cheese[i][j] -= melt[i][j];
				melt[i][j] = 0;
				cnt[i][j] = 0;
				checkEnd += cheese[i][j];
			}
		}
		++answer;

		if (checkEnd == 0)
			remain = false;
		checkEnd = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	Melt();

	cout << answer;

	return 0;
}