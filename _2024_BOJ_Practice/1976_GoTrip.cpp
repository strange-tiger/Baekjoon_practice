#include <iostream>
using namespace std;

int N, M;
bool able = true;
int parent[201];

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x < y)
		parent[y] = parent[x];
	else
		parent[x] = parent[y];
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; ++i)
		parent[i] = i;

	int connect;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> connect;

			if (connect)
				Union(i, j);
		}
	}
}

void solve()
{
	int front, back;

	cin >> back;
	for (int i = 1; i < M; ++i)
	{
		cin >> front;

		if (Find(front) != Find(back))
			able = false;

		back = front;
	}

	if (able)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
	input();
	solve();
	return 0;
}