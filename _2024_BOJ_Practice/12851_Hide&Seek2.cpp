#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int ver, dist;
int least = 100001;
int way = 0;
bool isVisited[100001] = { false };
queue<pair<int, int>> q;

void bfs()
{
	q.push({N, 0});
	
	while (!q.empty())
	{
		ver = q.front().first;
		dist = q.front().second;
		q.pop();
		isVisited[ver] = true;

		if (least < dist)
			break;

		if (ver == K)
		{
			least = dist;
			++way;
			continue;
		}

		if (ver < 100000 && !isVisited[ver + 1])
			q.push({ ver + 1, dist + 1 });
		if (ver > 0 && !isVisited[ver - 1])
			q.push({ ver - 1, dist + 1 });
		if (ver < 50001 && !isVisited[ver * 2])
			q.push({ ver * 2, dist + 1 });
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	bfs();

	printf("%d\n", least);
	printf("%d", way);

	return 0;
}
