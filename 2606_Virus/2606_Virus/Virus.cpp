#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> graph[101];
int ver, edge;
void dfs(int vortex, int& cnt)
{
	static bool isVisited[101] = { false };
	isVisited[vortex] = true;

	for (int next : graph[vortex])
	{
		if (!isVisited[next])
		{
			++cnt;

			dfs(next, cnt);
		}
	}
}

int main()
{
	scanf("%d %d", &ver, &edge);
	// 그래프 구성
	for (int i = 0; i < edge; ++i)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 정렬
	for (int i = 1; i <= ver; ++i)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	int count = 0;
	// 탐색
	dfs(1, count);

	printf("%d", count);
}