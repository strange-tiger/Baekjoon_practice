#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

#define r first
#define c second

std::vector<std::pair<int, int>> graph[300][300];
bool isVisited[300][300];
int count[300][300];

int bfs(std::pair<int, int> s, std::pair<int, int> e)
{

	std::queue<std::pair<int, int>> q;
	q.push(s);
	isVisited[s.r][s.c] = true;
	
	while (!q.empty())
	{
		std::pair<int, int> ver = q.front();
		q.pop();

		if (ver.r == e.r && ver.c == e.c)
		{
			break;
		}

		for (int i = 0; i < (int)graph[ver.r][ver.c].size(); ++i)
		{
			std::pair<int, int> next = graph[ver.r][ver.c][i];
			if (!isVisited[next.r][next.c])
			{
				q.push(next);
				isVisited[next.r][next.c] = true;
				count[next.r][next.c] = count[ver.r][ver.c] + 1;
			}
		}
	}

	return count[e.r][e.c];
}

int T, I;
std::pair<int, int> start, dest;
int main()
{
	scanf("%d", &T);

	while (T--)
	{
		for (int i = 0; i < 300; ++i)
		{
			memset(isVisited[i], false, 300 * sizeof(bool));
			memset(count[i], 0, 300 * sizeof(int));
			for (int j = 0; j < 300; ++j)
				graph[i][j].clear();
		}

		scanf("%d", &I);
		scanf("%d %d", &start.c, &start.r);
		scanf("%d %d", &dest.c, &dest.r);

		for (int i = 0; i < I; ++i)
		{
			for (int j = 0; j < I; ++j)
			{
				static int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
				static int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };

				for (int k = 0; k < 8; ++k)
				{
					int new_y = i + dy[k];
					int new_x = j + dx[k];

					if (new_y < 0 || new_y >= 300)
						continue;
					if (new_x < 0 || new_x >= 300)
						continue;

					graph[i][j].push_back({new_y, new_x});
				}
			}
		}

		int least = 0;
		least = bfs(start, dest);

		printf("%d\n", least);
	}
	return 0;
}