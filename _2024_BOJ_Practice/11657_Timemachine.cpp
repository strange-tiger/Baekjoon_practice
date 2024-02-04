#include <iostream>
#include <vector>
#include <utility>
#define INF 2000000000
using namespace std;

int N, M, A, B, C;
int i, j;
long long int dist[501];
vector<pair<int, int>> bus[501];

bool Bellman_Ford()
{
	dist[1] = 0;

	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			for (pair<int, int> n : bus[j])
				if (dist[j] != INF && dist[n.first] > n.second + dist[j])
					dist[n.first] = n.second + dist[j];

	for (i = 1; i <= N; ++i)
		for (j = 1; j <= N; ++j)
			for (pair<int, int> n : bus[j])
				if (dist[j] != INF && dist[n.first] > n.second + dist[j])
					return true;
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (i = 1; i <= N; ++i)
		dist[i] = INF;
	
	while (M--)
	{
		cin >> A >> B >> C;
		bus[A].push_back({ B, C });
	}

	if (Bellman_Ford())
		cout << "-1\n";
	else
		for (i = 2; i <= N; ++i)
		{
			if (dist[i] == INF)
				cout << "-1\n";
			else
				cout << dist[i] << '\n';
		}

	return 0;
}