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

void dfs()
{

	std::stack<int> st;
	st.push(R);

	int cnt = 0;
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		if (0 == isVisited[node])
		{
			++cnt;
			isVisited[node] = cnt;
		}

		for (int nextNode : graph[node])
		{
			if (0 == isVisited[nextNode])
			{
				st.push(nextNode);
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
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	dfs();
	for (int i = 1; i <= N; ++i)
	{
		printf("%d\n", isVisited[i]);
	}

	return 0;
}