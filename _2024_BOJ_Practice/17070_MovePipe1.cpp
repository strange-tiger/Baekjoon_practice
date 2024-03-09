#include <iostream>
using namespace std;

int N, answer = 0;
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };
int house[16][16] = { 0 };
bool isVisited[16][16] = { false };

// dir : 0 -> 가로 1 -> 세로 2 -> 대각선
void dfs(int x, int y, int dir)
{
	if (x == N - 1 && y == N - 1)
	{
		++answer;
		return;
	}

	isVisited[y][x] = true;

	int nx, ny;

	for (int i = 0; i < 3; ++i)
	{
		if ((dir == 0 && i == 1) || (dir == 1 && i == 0))
			continue;
		else
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (i < 2 && !house[ny][nx] && !isVisited[ny][nx])
				dfs(nx, ny, i);
			else if (i == 2 && nx > 0 && ny > 0 
				&& !house[ny][nx] && !house[ny][nx - 1] 
				&& !house[ny - 1][nx] && !isVisited[ny][nx])
				dfs(nx, ny, i);
		}
	}

	isVisited[y][x] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> house[i][j];
	
	dfs(1, 0, 0);

	cout << answer;

	return 0;
}