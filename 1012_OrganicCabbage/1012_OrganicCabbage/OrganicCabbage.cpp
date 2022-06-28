#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int T, M, N, K;
void dfs(int ver, int* cabbage, bool* isVisited)
{
	isVisited[ver] = true;

	int up = ver - M;
	int right = ver + 1;
	int left = ver - 1;
	int down = ver + M;

	if (up >= 0)
	{
		if (!isVisited[up])
		{
			if (1 == cabbage[up])
				dfs(up, cabbage, isVisited);
		}
	}

	if (right % M != 0)
	{
		if (!isVisited[right])
		{
			if (1 == cabbage[right])
				dfs(right, cabbage, isVisited);
		}
	}

	if (down < M * N)
	{
		if (!isVisited[down])
		{
			if (1 == cabbage[down])
				dfs(down, cabbage, isVisited);
		}
	}

	if (left % M != M - 1)
	{
		if (!isVisited[left])
		{
			if (1 == cabbage[left])
				dfs(left, cabbage, isVisited);
		}
	}
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		int cabbage[2500] = { 0 };
		bool isVisited[2500] = { false };

		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			cabbage[M * y + x] = 1;
		}

		int wormNum = 0;
		for (int i = 0; i < M * N; ++i)
		{
			if (1 == cabbage[i])
			{
				if (!isVisited[i])
				{
					++wormNum;
					dfs(i, cabbage, isVisited);
				}
			}
		}

		printf("%d\n", wormNum);
	}

	return 0;
}