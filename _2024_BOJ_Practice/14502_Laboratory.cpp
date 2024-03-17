#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int wallNum = 0;
int able;
int answer = 0;
int lab[8][8];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool isVisited[8][8] = { false };
vector<pair<int, int>> virus;
vector<pair<int, int>> check;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> lab[i][j];
			
			if (lab[i][j] == 2)
				virus.push_back({ j, i });
			else if (lab[i][j] == 1)
				++wallNum;
		}
	}

	wallNum += 3;
	able = N * M - wallNum;
}

int bfs(int sX, int sY)
{
	queue<pair<int, int>> q;
	q.push({ sX, sY });

	int x, y, cnt = 0;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (isVisited[y][x])
			continue;
		isVisited[y][x] = true;
		++cnt;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;

			if (lab[ny][nx] == 1)
				continue;

			if (!isVisited[ny][nx])
				q.push({ nx, ny });
		}
	}

	return cnt;
}

void wall(int depth, int ni, int nj)
{
	if (depth == 3)
	{
		int cnt = 0;

		memset(isVisited, false, sizeof(isVisited));
		for (pair<int, int> pos : virus)
			cnt += bfs(pos.first, pos.second);

		answer = max(answer, able - cnt);
		return;
	}

	for (int i = ni; i < N; ++i)
	{
		for (int j = nj; j < M; ++j)
		{
			if (lab[i][j] != 0)
				continue;
			
			lab[i][j] = 1;
			check.push_back({ i,j });
			if (j == M - 1)
				wall(depth + 1, i + 1, 0);
			else
				wall(depth + 1, i, j + 1);
			
			check.pop_back();
			lab[i][j] = 0;
		}
	}
}

void solve()
{
	wall(0, 0, 0);

	cout << answer;
}

int main()
{
	input();
	solve();

	return 0;
}