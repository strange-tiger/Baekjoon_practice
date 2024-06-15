#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2001
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h, a, b, d, tmp;
int dist[MAX][MAX];
vector<int> x;

void floydWarshall()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

void input()
{
	cin >> n >> m >> t;
	cin >> s >> g >> h;

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
			dist[i][j] = INF;
		if (i != 0)
			dist[i][i] = 0;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> d;
		dist[a][b] = min(dist[a][b], d);
		dist[b][a] = min(dist[b][a], d);
	}

	for (int i = 0; i < t; ++i)
	{
		cin >> tmp;
		x.push_back(tmp);
	}
	sort(x.begin(), x.end());
}

bool check(int start, int end)
{
	return (dist[start][end] == dist[start][g] + dist[g][h] + dist[h][end]
		|| dist[start][end] == dist[start][h] + dist[h][g] + dist[g][end]);
}

void solve()
{
	floydWarshall();

	for (int i : x)
		if (check(s, i))
			cout << i << ' ';
	cout << '\n';

	x.clear();
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