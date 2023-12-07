#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int ver;
int least = 100001;
int way = 0;
vector<int> graph[100001];
bool isVisited[100001] = { false };
int _count[100001] = { 0 };
queue<int> q;

void bfs()
{
	q.push(N);
	
	while (!q.empty())
	{
		ver = q.front();
		q.pop();
		isVisited[ver] = true;

		if (least < _count[ver])
			break;

		if (ver == K)
		{
			least = _count[ver];
			++way;
		}

		for (int next : graph[ver])
		{
			if (!isVisited[next])
			{
				q.push(next);
				_count[next] = _count[ver] + 1;
			}
		}
	}
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

	bfs();

	printf("%d\n", least);
	printf("%d", way);

	return 0;
}
