#include <iostream>
#include <queue>
#include <vector>
#define INF 100000001
using namespace std;

int N, M;
int s, e, cost;
vector<pair<int, int>> bus[1001];

vector<int> dijkstra(int start, int num)
{
	vector<int> cost(num + 1, INF);
	priority_queue<pair<int, int>> heap;

	cost[start] = 0;
	heap.push({ 0, start });

	int curCost, curCity, nxtCost, nxtCity;
	while (!heap.empty())
	{
		curCost = -heap.top().first;
		curCity = heap.top().second;
		heap.pop();

		for (int i = 0; i < bus[curCity].size(); ++i)
		{
			nxtCost = curCost + bus[curCity][i].second;
			nxtCity = bus[curCity][i].first;

			if (nxtCost < cost[nxtCity])
			{
				cost[nxtCity] = nxtCost;
				heap.push({ -nxtCost, nxtCity });
			}
		}
	}

	return cost;
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
		cin >> s >> e >> cost;
		bus[s].push_back({ e, cost });
	}

	cin >> s >> e;

	vector<int> cost = dijkstra(s, N);

	cout << cost[e];

	return 0;
}