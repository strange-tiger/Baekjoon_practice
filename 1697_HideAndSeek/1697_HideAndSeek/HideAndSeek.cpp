#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>

std::vector<int> graph[100001];
bool isVisited[100001] = { false };
int count[100001] = { 0 };

int bfs(int n, int k)
{

	std::queue<int> q;
	q.push(n);
	isVisited[n] = true;

	while (!q.empty())
	{
		int ver = q.front();
		q.pop();

		if (ver == k)
		{
			break;
		}

		for (int next : graph[ver])
		{
			if (!isVisited[next])
			{
				q.push(next);
				isVisited[next] = true;
				count[next] = count[ver] + 1;
			}
		}
	}

	return count[k];
}

int N, K;
int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < 100001; ++i)
	{
		if(i >= 0)
			graph[i].push_back(i - 1);
		if(i < 100001)
			graph[i].push_back(i + 1);
		if (i * 2 < 100001)
			graph[i].push_back(i * 2);
	}

	int least = 0;
	least = bfs(N, K);

	printf("%d", least);

	return 0;
}

#pragma region Without_BFS
// 43178933	pean04
// 재귀함수를 이용한 방법.
// 3가지 움직임의 경우는 모두 직전의 위치에 귀속된다.
/*
#include <cstdio>
int min(int a, int b)
{
	return a < b ? a : b;
}

int move(int a, int b)
{
	if (a <= b)
		return b - a;
	else if (a == 1)
		return 1;
	else if (a % 2 == 1)
		return 1 + min(move(a - 1, b), move(a + 1, b));
	else
		return min(a - b, 1 + move(a / 2, b));
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	printf("%d", move(K, N));
}
*/
#pragma endregion