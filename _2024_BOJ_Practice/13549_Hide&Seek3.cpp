#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int ver, dist;
bool isVisited[100001] = { false };
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int bfs()
{
	q.push({ 0, N });

	while (!q.empty())
	{
		dist = q.top().first;
		ver = q.top().second;
		q.pop();
		isVisited[ver] = true;

		if (ver == K)
			return dist;

		if (ver < 100000 && !isVisited[ver + 1])
			q.push({dist + 1, ver + 1});
		if (ver > 0 && !isVisited[ver - 1])
			q.push({ dist + 1, ver - 1 });
		if (ver < 50001 && !isVisited[ver * 2])
			q.push({ dist, ver * 2 });
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	printf("%d", bfs());

	return 0;
}
