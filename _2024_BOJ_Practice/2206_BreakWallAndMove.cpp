#include <iostream>
#include <queue>
#include <string>
#include <utility>
#define MAX 1000
using namespace std;

int N, M, i;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt[MAX][MAX][2];
string map[MAX];
queue<pair<pair<int, int>, int>> q;

int bfs()
{
	q.push({ { 0, 0 }, 1 });
	cnt[0][0][1] = 1;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int isBreakable = q.front().second;

		q.pop();

		if (x == M - 1 && y == N - 1)
			return cnt[y][x][isBreakable];

		for (i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (map[ny][nx] == '1' && isBreakable)
			{
				q.push({ { nx, ny }, 0 });
				cnt[ny][nx][0] = cnt[y][x][1] + 1;
			}
			else if (map[ny][nx] == '0' && cnt[ny][nx][isBreakable] == 0)
			{
				q.push({ { nx, ny }, isBreakable });
				cnt[ny][nx][isBreakable] = cnt[y][x][isBreakable] + 1;
			}
		}
	}
	
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (i = 0; i < N; ++i)
		cin >> map[i];

	cout << bfs();
	
	return 0;
}