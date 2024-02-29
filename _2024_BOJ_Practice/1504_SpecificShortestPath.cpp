#include <iostream>
#include <vector>
#include <queue>
#define INF 10e8
using namespace std;

int N, E, a, b, c, v1, v2, answer;
int Dist[2] = { 0 };
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
	
	int middle = dijkstra(v1, v2);
	if (middle >= INF)
	{
		cout << -1;
		return 0;
	}

	Dist[0] = dijkstra(1, v1) + middle + dijkstra(v2, N);
	Dist[1] = dijkstra(1, v2) + middle + dijkstra(v1, N);
	
	answer = min(Dist[0], Dist[1]);

	if (answer >= INF || answer < 0)
		cout << -1;
	else
		cout << answer;

	return 0;
}