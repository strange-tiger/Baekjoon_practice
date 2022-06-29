#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> graph[100001];
int N, M, R;

bool isVisited[100001] = { false };
int count[100001] = { 0 };

void bfs()
{
	std::queue<int> q;
	q.push(R);
	isVisited[R] = true;

	int cnt = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		++cnt;
		count[node] = cnt;

		for (int nextNode : graph[node])
		{
			if (!isVisited[nextNode])
			{
				q.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}

}

bool cmp(int a, int b)
{
	return a > b;
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

	bfs();
	for (int i = 1; i <= N; ++i)
	{
		printf("%d\n", count[i]);
	}

	return 0;
}