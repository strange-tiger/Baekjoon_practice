#include <iostream>
#define MAX 1000001
using namespace std;

int n, m;
int o, a, b;
int parent[MAX];

int Find(int x)
{
	if (parent[x] != x)
		return parent[x] = Find(parent[x]);
	return x;
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
}

void checkSet(int x, int y)
{
	if (Find(x) == Find(y))
		cout << "YES\n";
	else
		cout << "NO\n";
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; ++i)
		parent[i] = i;
}

void solve()
{
	while (m--)
	{
		cin >> o >> a >> b;

		if (o)
			checkSet(a, b);
		else
			Union(a, b);
	}
}

int main()
{
	input();
	solve();
	return 0;
}