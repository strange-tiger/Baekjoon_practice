#include <iostream>
using namespace std;

int N, M, sum = 0;
int memory[101];
int cost[101];
int dp[101][10001];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> memory[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[i];
		sum += cost[i];
	}
}

void solve()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i - 1][j - cost[i]] + memory[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0; i <= sum; ++i)
	{
		if (dp[N][i] >= M)
		{
			cout << i << '\n';
			break;
		}
	}
}

int main()
{
	input();
	solve();
	return 0;
}