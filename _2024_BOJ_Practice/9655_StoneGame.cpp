#include <iostream>
#include <algorithm>
using namespace std;

int N, i;
int dp[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (i = 3; i <= N; i++)
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);

	if (dp[N] % 2 == 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}