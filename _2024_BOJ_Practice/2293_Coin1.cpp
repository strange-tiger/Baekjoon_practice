#include <iostream>
using namespace std;

int n, k;
int val[101] = { 0 };
int dp[10001] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> val[i];
}

void DP()
{
	dp[0] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = val[i]; j <= k; ++j)
			dp[j] += dp[j - val[i]];

	cout << dp[k];
}

int main()
{
	input();
	DP();
	return 0;
}