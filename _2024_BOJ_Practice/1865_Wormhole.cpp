#include <iostream>
#include <vector>
#include <utility>
#define INF 1000000000
using namespace std;

int TC, N, M, W;
int S, E, T;
int i, j;
bool cycle = false;
int dist[501];
vector<pair<int, int>> road[501];

void Init()
{
	for (i = 1; i <= N; ++i)
	{
		dist[i] = INF;
		road[i].clear();
	}
}

bool Bellman_Ford(int n)
{
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (pair<int, int> way : road[j])
				if (dist[way.first] > way.second + dist[j])
					dist[way.first] = way.second + dist[j];

	for (i = 1; i <= n; ++i) // 음의 사이클 찾기
		for (pair<int, int> way : road[i])
			if (dist[way.first] > way.second + dist[i])
				return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;
	
	while (TC--)
	{
		Init();

		cin >> N >> M >> W;

		dist[1] = 0;

		for (i = 0; i < M; ++i)
		{
			cin >> S >> E >> T;
			road[S].push_back({ E, T });
			road[E].push_back({ S, T });
		}

		for (i = 0; i < W; ++i)
		{
			cin >> S >> E >> T;
			road[S].push_back({ E, -T });
		}

		if (Bellman_Ford(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}