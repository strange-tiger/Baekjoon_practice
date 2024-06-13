#include <iostream>
#include <vector>
#define MAX 500000
using namespace std;

int n, m, ans = 0;
int parent[MAX];
bool isCycle = false;

int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int a, int b)
{
	int x = findParent(a);
	int y = findParent(b);

	if (x != y)
	{
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		parent[i] = i;

	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;

		if (!isCycle && (findParent(a) == b || findParent(b) == a))
			ans = i + 1;

		merge(a, b);
	}
}

void solve()
{
	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}