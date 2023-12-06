#include <iostream>
#include <queue>
#include <vector>
#define INF 100000001
using namespace std;

int N, M;
int s, e, c;
vector<int> cost(1001, INF);
vector<pair<int, int>> bus[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

void dijkstra(int start)
{
	cost[start] = 0;
	heap.push({ 0, start });

	int curCost, curCity, nxtCost, nxtCity;
	while (!heap.empty())
	{
		curCost = heap.top().first;
		curCity = heap.top().second;
		heap.pop();

		for (int i = 0; i < bus[curCity].size(); ++i)
		{
			nxtCost = curCost + bus[curCity][i].second;
			nxtCity = bus[curCity][i].first;

			if (nxtCost < cost[nxtCity])
			{
				cost[nxtCity] = nxtCost;
				heap.push({ nxtCost, nxtCity });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> M;
	
	while (M--)
	{
		cin >> s >> e >> c;
		bus[s].push_back({ e, c });
	}

	cin >> s >> e;

	dijkstra(s);

	cout << cost[e];

	return 0;
}