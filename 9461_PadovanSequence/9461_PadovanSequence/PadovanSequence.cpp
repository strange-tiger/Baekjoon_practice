#include <iostream>
using namespace std;

long long dp[100] = { 0 };
int T, N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < 100; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	cin >> T;
	while (T--)
	{
		cin >> N;

		cout << dp[N - 1] << "\n";
	}

	return 0;
}