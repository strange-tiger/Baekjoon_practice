#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001
using namespace std;

int N, M;
int s, e, c;
int beforeCity[1001] = { 0 };
vector<int> path;
vector<int> cost(1001, INF);
vector<pair<int, int>> bus[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

void Input()
{
	cin >> N >> M;

	while (M--)
	{
		cin >> s >> e >> c;
		bus[s].push_back({ e, c });
	}

	cin >> s >> e;
}

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

		int busSize = bus[curCity].size();
		for (int i = 0; i < busSize; ++i)
		{
			nxtCost = curCost + bus[curCity][i].second;
			nxtCity = bus[curCity][i].first;

			if (nxtCost < cost[nxtCity])
			{
				beforeCity[nxtCity] = curCity;
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

	Input();

	dijkstra(s);

	cout << cost[e] << '\n';

	while (e != 0)
	{
		path.push_back(e);
		e = beforeCity[e];
	}

	int size = path.size();
	cout << size << '\n';
	for (int i = size - 1; i >= 0; --i)
		cout << path[i] << ' ';

	return 0;
}