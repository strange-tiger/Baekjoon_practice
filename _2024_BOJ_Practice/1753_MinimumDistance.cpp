#include <iostream>
#include <queue>
#include <vector>
#define INF 3000001
using namespace std;

int V, E, K;
int u, v, w;
vector<int> dist(20001, INF);
vector<pair<int, int>> vertex[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

int curDist, curNode, nxtDist, nxtNode;
void dijkstra()
{
	dist[K] = 0;
	heap.push({ 0, K });

	while (!heap.empty())
	{
		curDist = heap.top().first;
		curNode = heap.top().second;
		heap.pop();

		for (int i = 0; i < vertex[curNode].size(); ++i)
		{
			nxtDist = curDist + vertex[curNode][i].second;
			nxtNode = vertex[curNode][i].first;

			if (nxtDist < dist[nxtNode])
			{
				dist[nxtNode] = nxtDist;
				heap.push({ nxtDist, nxtNode });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	cin >> K;

	while (E--)
	{
		cin >> u >> v >> w;
		vertex[u].push_back({ v, w });
	}

	dijkstra();

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}