#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, c, ans = 0;
int medal[1001][3];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> c;

		for (int j = 0; j < 3; ++j)
			cin >> medal[c][j];
	}
}

void solve()
{
	for (int i = 1; i <= N; ++i)
	{
		if (i == K)
			continue;

		for (int j = 0; j < 3; ++j)
		{
			if (medal[i][j] > medal[K][j])
			{
				++ans;
				break;
			}
			else if (medal[i][j] < medal[K][j])
				break;
		}
	}

	cout << ++ans;
}

int main()
{
	input();
	solve();
	return 0;
}