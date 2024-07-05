#include <iostream>
using namespace std;

int N, M, r, c, d;
int room[50][50];
bool isVisited[50][50] = { false };

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dfs(int x, int y, int dir, int sum)
{
	int ndir, nx, ny;
	for (int i = 0; i < 4; ++i)
	{
		ndir = (dir + 3 - i) % 4;

		nx = x + dx[ndir];
		ny = y + dy[ndir];

		if (nx < 0 || ny < 0 || nx >= M || ny >= N || room[ny][nx] == 1 || isVisited[ny][nx])
			continue;

		isVisited[ny][nx] = true;
		dfs(nx, ny, ndir, sum + 1);
	}

	int bdir = (dir + 2) % 4;
	int bx = x + dx[bdir];
	int by = y + dy[bdir];

	if (bx < 0 || by < 0 || bx > M || by > N)
		return;
	
	if (room[by][bx] == 0)
		dfs(bx, by, dir, sum);
	else
	{
		cout << sum;
		exit(0);
	}
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> room[i][j];
}

void solve()
{
	isVisited[r][c] = true;
	dfs(c, r, d, 1);
}

int main()
{
	input();
	solve();
	return 0;
}