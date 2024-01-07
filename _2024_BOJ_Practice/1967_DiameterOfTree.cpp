#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int a, b, w;
int diameter = 0;
int endNode = 0;
bool isVisited[10001] = { false };
vector<pair<int, int>> node[10001];

void dfs(int n, int len)
{
	if (isVisited[n])
		return;

	isVisited[n] = true;
	if (diameter < len)
	{
		diameter = len;
		endNode = n;
	}

	for (pair<int, int> next : node[n])
		dfs(next.first, len + next.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	while (--N)
	{
		cin >> a >> b >> w;
		node[a].push_back({ b, w });
		node[b].push_back({ a, w });
	}

	dfs(1, 0);
	memset(isVisited, false, sizeof(isVisited));
	dfs(endNode, 0);

	cout << diameter;

	return 0;
}