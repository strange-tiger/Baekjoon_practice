#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int N, ans = 0;
int A[MAX];
int dp[MAX];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		dp[i] = 1;
		
		for (int j = 0; j < i; ++j)
			if (A[i] > A[j])
				dp[i] = max(dp[i], dp[j] + 1);

		ans = max(ans, dp[i]);
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}