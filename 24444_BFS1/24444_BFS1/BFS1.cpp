#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> graph[100001];
int N, M, R;

int isVisited[100001] = { 0 };

void bfs()
{

	std::queue<int> q;
	q.push(R);

	int cnt = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (0 == isVisited[node])
		{
			++cnt;
			isVisited[node] = cnt;
		}

		for (int nextNode : graph[node])
		{
			if (0 == isVisited[nextNode])
			{
				q.push(nextNode);
			}
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
		sort(graph[i].begin(), graph[i].end());
	}

	bfs();
	for (int i = 1; i <= N; ++i)
	{
		printf("%d\n", isVisited[i]);
	}

	return 0;
}