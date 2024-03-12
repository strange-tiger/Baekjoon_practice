#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000001
using namespace std;

int n, m, r;
int i, j, k;
int a, b, I;
int item[101] = { 0 };
int dist[101][101];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;
	for (i = 1; i <= n; ++i)
		cin >> item[i];
	
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j <= n; ++j)
			dist[i][j] = INF;

		if (i != 0)
			dist[i][i] = 0;
	}

	while (r--)
	{
		cin >> a >> b >> I;

		dist[a][b] = min(dist[a][b], I);
		dist[b][a] = min(dist[b][a], I);
	}
}

void floyd_warshall()
{
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 1; k <= n; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int Max = 0;
int sum = 0;
int search()
{	
	for (i = 1; i <= n; ++i)
	{
		sum = 0;

		for (j = 1; j <= n; ++j)
			if (m >= dist[i][j])
				sum += item[j];

		Max = max(Max, sum);
	}

	return Max;
}

int main()
{
	input();

	floyd_warshall();

	cout << search();

	return 0;
}