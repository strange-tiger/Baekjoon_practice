#include <iostream>
using namespace std;

int N, M, K, sx, sy, x, y;
int sum[301][301] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> sum[i][j];
			sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	cin >> K;
}

void solve()
{
	cin >> sx >> sy >> x >> y;
	cout << sum[x][y] - sum[sx - 1][y] - sum[x][sy - 1] + sum[sx - 1][sy - 1] << '\n';
}

int main()
{
	input();
	while (K--)
		solve();
	return 0;
}