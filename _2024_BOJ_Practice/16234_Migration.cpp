#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

int N, L, R, ans = 0;
int A[50][50];
pair<int, int> parent[50][50];
bool isDif = true;
int unionNum[50][50][2];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> A[i][j];
}

void init()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			parent[i][j] = { j, i };
			unionNum[i][j][0] = 1;
			unionNum[i][j][1] = A[i][j];
		}
	}

	isDif = false;
}

pair<int, int> findParent(pair<int, int> x)
{
	if (parent[x.second][x.first] != x)
		return parent[x.second][x.first] = findParent(parent[x.second][x.first]);
	return x;
}

void merge(pair<int, int> a, pair<int, int> b)
{
	pair<int, int> x = findParent(a);
	pair<int, int> y = findParent(b);

	if (x != y)
	{
		if (x.second < y.second)
			parent[y.second][y.first] = x;
		else if (x.second == y.second && x.first < y.first)
			parent[y.second][y.first] = x;
		else
			parent[x.second][x.first] = y;

		unionNum[x.second][x.first][0] += unionNum[y.second][y.first][0];
		unionNum[y.second][y.first][0] = unionNum[x.second][x.first][0];
		unionNum[x.second][x.first][1] += unionNum[y.second][y.first][1];
		unionNum[y.second][y.first][1] = unionNum[x.second][x.first][1];
	}
}

void checkDif(pair<int, int> x, pair<int, int> y)
{
	int dif = abs(A[x.second][x.first] - A[y.second][y.first]);

	if (dif >= L && dif <= R)
	{
		merge(x, y);
		isDif = true;
	}
}

void solve()
{
	while (isDif)
	{
		init();

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (j < N - 1)
					checkDif({ j, i }, { j + 1, i });
				if (i < N - 1)
					checkDif({ j, i }, { j, i + 1 });
			}
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				A[i][j] = unionNum[i][j][1] / unionNum[i][j][0];

		if (isDif)
			++ans;
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}