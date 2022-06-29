#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <utility>
#include <queue>

char grid[100][100];
int gridCount[100][100] = { 0 };
int result = 10001;
int current = 0;

int n, m;

void dfs(int x, int y)
{
	++current;

	if (x == n - 1 && y == m - 1)
	{
		if (result > current)
		{
			result = current;
		}
		--current;
		return ;
	}

	grid[x][y] = '0';

	//아래쪽
	if (x < n-1 && grid[x + 1][y] == '1')
	{
		dfs(x + 1, y);
	}
	//오른쪽
	if (y < m - 1 && grid[x][y + 1] == '1')
	{
		dfs(x, y + 1);
	}
	//왼쪽
	if (y > 0 && grid[x][y - 1] == '1')
	{
		dfs(x, y - 1);
	}
	//위쪽
	if (x > 0 && grid[x - 1][y] == '1')
	{
		dfs(x - 1, y);
	}

	grid[x][y] = '1';
	--current;
	return ;
}

void bfs()
{
	std::queue<std::pair<int, int>> bfs;
	bfs.push({ 0, 0 });
	grid[0][0] = '0';
	++gridCount[0][0];

	while (bfs.empty() == false)
	{
		std::pair<int, int> data = bfs.front();
		bfs.pop();

		if (data.first == n - 1 && data.second == m - 1)
		{
			break;
		}

		//아래쪽
		if (data.first < n - 1 && grid[data.first + 1][data.second] == '1')
		{
			bfs.push({ data.first + 1, data.second });
			grid[data.first + 1][data.second] = '0';
			gridCount[data.first + 1][data.second] = 
				gridCount[data.first][data.second] + 1;
		}
		//오른쪽
		if (data.second < m - 1 && grid[data.first][data.second + 1] == '1')
		{
			bfs.push({ data.first, data.second + 1 });
			grid[data.first][data.second + 1] = '0';
			gridCount[data.first][data.second + 1] =
				gridCount[data.first][data.second] + 1;
		}
		//위쪽
		if (data.first > 0 && grid[data.first - 1][data.second] == '1')
		{
			bfs.push({ data.first - 1, data.second });
			grid[data.first - 1][data.second] = '0';
			gridCount[data.first - 1][data.second] =
				gridCount[data.first][data.second] + 1;
		}
		//왼쪽
		if (data.second > 0 && grid[data.first][data.second - 1] == '1')
		{
			bfs.push({ data.first, data.second - 1 });
			grid[data.first][data.second - 1] = '0';
			gridCount[data.first][data.second - 1] =
				gridCount[data.first][data.second] + 1;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", grid[i]);
	}

	bfs();

	printf("%d", gridCount[n - 1][m - 1]);

	return 0;
}