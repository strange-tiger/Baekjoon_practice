#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
int Min = MAX;
int cost[1000][3];
int dp[1001][3] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
}

void solve()
{
	for (int s = 0; s < 3; ++s)
	{
		dp[1][s] = cost[0][s];
		dp[1][(s + 1) % 3] = MAX;
		dp[1][(s + 2) % 3] = MAX;

		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				dp[i + 1][j] = min(dp[i][(j + 1) % 3], dp[i][(j + 2) % 3]);
				dp[i + 1][j] += cost[i][j];
			}
		}

		Min = min(Min, dp[N][(s + 1) % 3]);
		Min = min(Min, dp[N][(s + 2) % 3]);
	}

	cout << Min;
}

int main(void)
{
	input();
	solve();
	return 0;
}