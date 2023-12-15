#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

int n, m;
int a, b, c;
int i, j, k;
int dist[101][101];

void floyd_warshall()
{
	for (i = 1; i < n + 1; ++i)
		for (j = 1; j < n + 1; ++j)
			for (k = 1; k < n + 1; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (i = 0; i < n + 1; ++i)
	{
		for (j = 0; j < n + 1; ++j)
		{
			dist[i][j] = INF;
		}

		if (i != 0)
			dist[i][i] = 0;
	}

	while (m--)
	{
		cin >> a >> b >> c;
		
		dist[a][b] = min(dist[a][b], c);
	}

	floyd_warshall();
	
	for (i = 1; i < n + 1; ++i)
	{
		for (j = 1; j < n + 1; ++j)
		{
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}

		cout << '\n';
	}

	return 0;
}