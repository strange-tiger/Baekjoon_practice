#include <iostream>
using namespace std;

int N;
int ans[3] = { 0 };
int paper[2187][2187];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> paper[i][j];
			++paper[i][j];
		}
	}
}

bool isUnified(int n, int x, int y)
{
	int start = paper[y][x];
	for (int i = y; i < y + n; ++i)
		for (int j = x; j < x + n; ++j)
			if (start != paper[i][j])
				return false;
	return true;
}

void quadtree(int n, int x, int y)
{
	int cnt = 0;

	if (isUnified(n, x, y))
		++ans[paper[y][x]];
	else
	{
		int size = n / 3;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				quadtree(size, x + j * size, y + i * size);
	}
}

void solve()
{
	quadtree(N, 0, 0);
	
	for (int i = 0; i < 3; ++i)
		cout << ans[i] << '\n';
}

int main()
{
	input();
	solve();
	return 0;
}