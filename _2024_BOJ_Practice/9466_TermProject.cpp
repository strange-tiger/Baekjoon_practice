#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int T, n, cnt;
int s[MAX];
bool isVisited[MAX];
bool isCycle[MAX];

void dfs(int node)
{
	isVisited[node] = true;

	int next = s[node];
	if (!isVisited[next])
		dfs(next);
	else if (!isCycle[next])
	{
		for (int i = next; i != node; i = s[i])
		{
			++cnt;
			//isCycle[i] = true;
		}
		++cnt;
	}
	isCycle[node] = true;
}

void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		cin >> s[i];
}

void solve()
{
	for (int i = 1; i <= n; ++i)
		if (!isVisited[i])
			dfs(i);

	cout << n - cnt << '\n';
	cnt = 0;
	memset(isVisited, false, sizeof(isVisited));
	memset(isCycle, false, sizeof(isCycle));
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