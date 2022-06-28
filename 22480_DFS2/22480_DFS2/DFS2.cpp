#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> graph[100001];
int N, M, R;

bool cmp(int a, int b)
{
	return a > b;
}

int isVisited[100001] = { 0 };

void dfs(int vertex, int& cnt)
{
	for (int next : graph[vertex])
	{
		if (0 == isVisited[next])
		{
			++cnt;
			isVisited[next] = cnt;
			dfs(next, cnt);
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &R);
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	int count = 1;
	isVisited[R] = count;
	dfs(R, count);
	for (int i = 1; i <= N; ++i)
	{
		printf("%d\n", isVisited[i]);
	}

	return 0;
}