#include <iostream>
#include <vector>
#define MAX 101
#define INF 1e9
using namespace std;

int N, M;
int a, b, c;
int cost[MAX][MAX];
int route[MAX][MAX];
vector<int> v;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cost[i][j] = INF;

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		cost[a][b] = cost[a][b] < c ? cost[a][b] : c;
	}
}

void Floyd_Warshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j)
					continue;
				if (cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
					route[i][j] = k;
				}
			}
		}
	}
}

void setRoute(int s, int e)
{
	if (route[s][e] == 0)
	{
		v.push_back(s);
		v.push_back(e);
		return;
	}
	else
	{
		setRoute(s, route[s][e]);
		v.pop_back();
		setRoute(route[s][e], e);
	}
}

void solve()
{
	Floyd_Warshall();

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (cost[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << cost[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (cost[i][j] == INF)
				cout << 0;
			else
			{
				v.clear();
				setRoute(i, j);

				cout << v.size() << ' ';
				for (int k = 0; k < v.size(); ++k)
					cout << v[k] << ' ';
			}
			cout << '\n';
		}
	}
}

int main()
{
	input();
	solve();
	return 0;
}