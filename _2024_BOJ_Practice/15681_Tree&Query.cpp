#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int N, R, Q;
int parent[MAX] = { 0 };
int dp[MAX] = { 0 };
bool isVisited[MAX] = { false };
vector<int> g[MAX];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;

	int u, v;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void dfs(int node)
{
	isVisited[node] = true;
	for (int next : g[node])
	{
		if (isVisited[next])
			continue;
		parent[next] = node;
		dfs(next);
	}

	if (parent[node] > 0)
		dp[parent[node]] += dp[node];
}

int childNum(int u)
{
	return dp[u];
}

void solve()
{
	for (int i = 1; i <= N; ++i)
		dp[i] = 1;

	parent[R] = -1;
	dfs(R);

	int u;
	while (Q--)
	{
		cin >> u;
		cout << childNum(u) << '\n';
	}
}

int main()
{
	input();
	solve();
	return 0;
}