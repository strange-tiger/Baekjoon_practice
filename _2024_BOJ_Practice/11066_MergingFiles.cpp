#include <iostream>
#include <algorithm>
using namespace std;

int T, K;
int sum[501] = { 0 };
int dp[501][501];

void input()
{
	cin >> K;

	for (int i = 1; i <= K; ++i)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
}

void solve()
{
	for (int i = 1; i < K; ++i)
	{
		int s = 1;
		int e = i + 1;

		for (int j = 0; j < K - i; ++j)
		{
			dp[s][e] = 1e9;

			for (int k = e - i; k < e; ++k)
				dp[s][e] = min(dp[s][e], dp[s][k] + dp[k + 1][e] + sum[e] - sum[s - 1]);
			++s;
			++e;
		}
	}
	cout << dp[1][K] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		input();
		solve();
	}
	return 0;
}