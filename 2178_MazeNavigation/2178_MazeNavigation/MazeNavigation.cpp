#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int M, N, K;
bool isVisited[10000] = { false };
int count[10000] = { 0 };

void bfs(int* maze)
{
	std::queue<int> path;
	path.push(0);
	isVisited[0] = true;
	count[0] = 1;

	while (!path.empty())
	{
		int ver = path.front();
		path.pop();

		int up = ver - M;
		int right = ver + 1;
		int left = ver - 1;
		int down = ver + M;

		if (up >= 0)
		{
			if (!isVisited[up])
			{
				if (1 == maze[up])
				{
					path.push(up);
					isVisited[up] = true;
					
					count[up] = count[ver] + 1;
				}
			}
		}

		if (right % M != 0)
		{
			if (!isVisited[right])
			{
				if (1 == maze[right])
				{
					path.push(right);
					isVisited[right] = true;
					
					count[right] = count[ver] + 1;
				}
			}
		}

		if (down < M * N)
		{
			if (!isVisited[down])
			{
				if (1 == maze[down])
				{
					path.push(down);
					isVisited[down] = true;
					
					count[down] = count[ver] + 1;
				}
			}
		}

		if (left % M != M - 1)
		{
			if (!isVisited[left])
			{
				if (1 == maze[left])
				{
					path.push(left);
					isVisited[left] = true;
					
					count[left] = count[ver] + 1;
				}
			}
		}
	}
}

int main()
{
	int maze[10000] = { 0 };

	scanf("%d %d", &N, &M);

	int cnt = 0;
	while (cnt < M * N)
	{
		int temp = getchar() - '0';
		if (1 == temp || 0 == temp)
		{
			maze[cnt] = temp;
			++cnt;
		}
	}

	bfs(maze);

	printf("%d\n", count[M * N - 1]);

	return 0;
}