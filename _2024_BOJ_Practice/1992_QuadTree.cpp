#include <iostream>
#include <string>
using namespace std;

int N;
string str;
int photo[64][64];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		for (int j = 0; j < N; ++j)
			photo[i][j] = str[j] - '0';
	}
}

void quadtree(int n, int x, int y)
{
	int cnt = 0;

	if (n == 1)
	{
		cout << photo[y][x];
		return;
	}

	for (int i = y; i < y + n; ++i)
		for (int j = x; j < x + n; ++j)
			if (photo[i][j])
				++cnt;

	if (cnt == n * n)
		cout << 1;
	else if (cnt == 0)
		cout << 0;
	else
	{
		cout << '(';
		quadtree(n / 2, x, y);
		quadtree(n / 2, x + n / 2, y);
		quadtree(n / 2, x, y + n / 2);
		quadtree(n / 2, x + n / 2, y + n / 2);
		cout << ')';
	}
}

void solve()
{
	quadtree(N, 0, 0);
}

int main()
{
	input();
	solve();
	return 0;
}