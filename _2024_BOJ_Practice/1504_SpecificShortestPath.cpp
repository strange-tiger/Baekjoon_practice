#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
using namespace std;

int N, E, a, b, c, v1, v2;
int answer = 0;
int Dist[3];
vector<pair<int, int>> g[801];

void Input()
{
	cin >> N >> E;

	while (E--)
	{
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
}

int dijkstra(int start, int end)
{
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> heap;

	dist[0] = 0;
	dist[start] = 0;
	heap.push({ 0, start });

	int curDist, curNode, nxtDist, nxtNode;
	while (!heap.empty())
	{
		curDist = -heap.top().first;
		curNode = heap.top().second;
		heap.pop();

		for (int i = 0; i < g[curNode].size(); ++i)
		{
			if (g[curNode][i].second != INF)
				nxtDist = curDist + g[curNode][i].second;
			else
				nxtDist = INF;

			nxtNode = g[curNode][i].first;

			if (nxtDist < dist[nxtNode])
			{
				dist[nxtNode] = nxtDist;
				heap.push({ -nxtDist, nxtNode });
			}
		}
	}

	return dist[end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();
	
	Dist[0] = dijkstra(1, v1);
	Dist[1] = dijkstra(v1, v2);
	Dist[2] = dijkstra(v2, N);

	for (int d : Dist)
	{
		if (d >= INF)
		{
			cout << -1;
			return 0;
		}
		answer += d;
	}
	
	cout << answer;

	return 0;
}