#include <iostream>
#include <algorithm>
#define INF 1e9
#define MAX 401
using namespace std;

int V, E, ans = INF;
int a, b, c;
int road[401][401];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			road[i][j] = INF;

	cin >> V >> E;

	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		road[a][b] = c;
	}
}

void floydWarshall()
{
	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			for (int k = 1; k <= V; ++k)
				road[j][k] = min(road[j][k], road[j][i] + road[i][k]);
}

void solve()
{
	floydWarshall();

	for (int i = 1; i <= V; ++i)
		for (int j = 1; j <= V; ++j)
			ans = min(ans, road[i][j] + road[j][i]);

	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}