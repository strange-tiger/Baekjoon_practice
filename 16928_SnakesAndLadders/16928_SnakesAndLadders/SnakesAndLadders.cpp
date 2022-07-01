#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int graph[101] = { 0 };
int bfs()
{
	int cnt[101] = { 0 };
	memset(cnt, -1, sizeof(cnt));

	queue<int> q;
	q.push(1);
	cnt[1] = 0;

	while (!q.empty())
	{
		int ver = q.front();
		q.pop();

		if (ver == 100)
		{
			return cnt[ver];
		}

		for (int i = 1; i <= 6; ++i)
		{
			int nVer = ver + i;
			if (nVer > 100)
			{
				continue;
			}

			if (graph[nVer] != 0)
			{
				nVer = graph[nVer];
			}

			if (cnt[nVer] == -1)
			{
				q.push(nVer);
				cnt[nVer] = cnt[ver] + 1;
			}
		}
	}

	return cnt[100];
}

int N, M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x] = y;
	}

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}

	int diceMin = bfs();

	cout << diceMin;

	return 0;
}