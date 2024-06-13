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

int main()
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

		if (findParent(a) == findParent(b))
		{
			cout << i + 1;
			return 0;
		}

		merge(a, b);
	}
	cout << 0;

	return 0;
}