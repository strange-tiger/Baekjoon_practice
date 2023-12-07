#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int least, way;
vector<int> graph[100001];
bool isVisited[100001] = { false };
int _count[100001] = { 0 };
queue<int> q;

void bfs(int n, int k)
{
	q.push(n);
	isVisited[n] = true;

	while (!q.empty())
	{
		int ver = q.front();
		q.pop();

		for (int next : graph[ver])
		{
			if (!isVisited[next])
			{
				q.push(next);
				isVisited[next] = true;
				_count[next] = _count[ver] + 1;

				if (next == k)
					way = 1;
			}

			if (isVisited[next] && _count[next] > _count[ver] + 1)
			{
				q.push(next);
				_count[next] = _count[ver] + 1;

				if (next == k)
					way = 1;
			}

			if (_count[next] == _count[ver] + 1 && next == k)
				++way;
		}
	}

	least = _count[k];
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < 100001; ++i)
	{
		if (i > 0)
			graph[i].push_back(i - 1);
		if (i < 100000)
			graph[i].push_back(i + 1);
		if (i * 2 < 100001)
			graph[i].push_back(i * 2);
	}

	bfs(N, K);

	printf("%d\n", least);
	printf("%d", way);

	return 0;
}