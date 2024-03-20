#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int dp[16] = { 0 };
int T[16];
int P[16];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> T[i] >> P[i];
}

void solve()
{
	int time;
	for (int i = N - 1; i >= 0; --i)
	{
		time = i + T[i];
		if (time <= N)
			dp[i] = max(dp[i + 1], dp[time] + P[i]);
		else
			dp[i] = dp[i + 1];
	}

	cout << dp[0];
}

int main()
{
	input();
	solve();
	return 0;
}