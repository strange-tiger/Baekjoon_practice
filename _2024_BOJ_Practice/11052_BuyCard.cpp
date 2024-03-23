#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int N;
int P[MAX] = { 0 };
int dp[MAX] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> P[i];
}

void solve()
{
	dp[0] = 0;
	P[0] = 0;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			dp[i] = max(dp[i], dp[i - j] + P[j]);

	cout << dp[N];
}

int main()
{
	input();
	solve();
	return 0;
}
