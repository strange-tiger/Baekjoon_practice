#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
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

		if (cost[curCity] < curCost)
			continue;

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
	scanf("%d", &N);
	scanf("%d", &M);
	
	while (M--)
	{
		scanf("%d %d %d", &s, &e, &c);
		bus[s].push_back({ e, c });
	}

	scanf("%d %d", &s, &e);

	dijkstra(s);

	printf("%d", cost[e]);

	return 0;
}