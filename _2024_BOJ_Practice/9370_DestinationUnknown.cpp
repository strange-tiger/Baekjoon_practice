#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 2001
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h, a, b, d, tmp;
int distS[MAX];
int distG[MAX];
int distH[MAX];
vector<pair<int, int>> graph[MAX];
priority_queue<int, vector<int>, greater<int>> x;

void init()
{
	for (int i = 0; i < MAX; ++i)
	{
		graph[i].clear();
		distS[i] = INF;
		distG[i] = INF;
		distH[i] = INF;
	}
}

void dijkstra(int start, int dist[MAX])
{
	priority_queue<pair<int, int>> heap;
	heap.push({ 0, start });
	dist[start] = 0;

	int curDist, curNode, nxtDist, nxtNode;
	while (!heap.empty())
	{
		curDist = -heap.top().first;
		curNode = heap.top().second;
		heap.pop();

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			nxtDist = curDist + graph[curNode][i].first;
			nxtNode = graph[curNode][i].second;

			if (dist[nxtNode] > nxtDist)
			{
				dist[nxtNode] = nxtDist;
				heap.push({ -nxtDist, nxtNode });
			}
		}
	}
}

void input()
{
	init();

	cin >> n >> m >> t;
	cin >> s >> g >> h;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> d;
		graph[a].push_back({ d, b });
		graph[b].push_back({ d, a });
	}

	for (int i = 0; i < t; ++i)
	{
		cin >> tmp;
		x.push(tmp);
	}
}

bool check(int end)
{
	return (distS[end] == distS[g] + distG[h] + distH[end]
		|| distS[end] == distS[h] + distH[g] + distG[end]);
}

void solve()
{
	dijkstra(s, distS);
	dijkstra(g, distG);
	dijkstra(h, distH);

	while (!x.empty())
	{
		int dest = x.top();
		x.pop();

		if (check(dest))
			cout << dest << ' ';
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		input();
		solve();
	}

	return 0;
}