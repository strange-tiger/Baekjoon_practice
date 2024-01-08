#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V;
int a, b, w;
int diameter = 0;
int endNode = 0;
bool isVisited[100001] = { false };
vector<pair<int, int>> node[100001];

void dfs(int v, int len)
{
	if (isVisited[v])
		return;

	isVisited[v] = true;
	if (diameter < len)
	{
		diameter = len;
		endNode = v;
	}

	for (pair<int, int> next : node[v])
		dfs(next.first, len + next.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;

	while (V--)
	{
		cin >> a;

		while (cin >> b, b > 0)
		{
			cin >> w;
			node[a].push_back({ b, w });
			node[b].push_back({ a, w });
		}
	}

	dfs(1, 0);
	memset(isVisited, false, sizeof(isVisited));
	dfs(endNode, 0);

	cout << diameter;

	return 0;
}