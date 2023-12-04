#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int map[1000][1000];
int distance[1000][1000];
bool isVisited[1000][1000];

void bfs()
{
	static int dx[] = { 1, 0, -1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}

	return 0;
}