#include <iostream>
using namespace std;

char grid[101][101] = { 0 };
bool isVisited[101][101] = { false };
static int dr[] = { -1, 1, 0, 0 };
static int dc[] = { 0, 0, -1, 1 };
int N;

void dfs(int r, int c, char ch)
{
	isVisited[r][c] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;
		
		if(!isVisited[nr][nc])
			if(grid[nr][nc] == ch)
				dfs(nr, nc, ch);
	}
}

void dfs_RG(int r, int c, char ch)
{
	isVisited[r][c] = true;

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;

		if (!isVisited[nr][nc])
		{
			if (ch == 'R' || ch == 'G')
			{
				if (grid[nr][nc] == 'R' || grid[nr][nc] == 'G')
				{
					dfs_RG(nr, nc, ch);
				}
			}
			else if (grid[nr][nc] == ch)
			{
				dfs_RG(nr, nc, ch);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			cin >> grid[r][c];
		}
	}

	int areaNum = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (!isVisited[r][c])
			{
				char areaCh = grid[r][c];
				++areaNum;
				dfs(r, c, areaCh);
			}
		}
	}

	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			isVisited[r][c] = false;
		}
	}

	int areaNum_RG = 0;
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < N; ++c)
		{
			if (!isVisited[r][c])
			{
				char areaCh_RG = grid[r][c];
				++areaNum_RG;
				dfs_RG(r, c, areaCh_RG);
			}
		}
	}

	cout << areaNum << " " << areaNum_RG;

	return 0;
}