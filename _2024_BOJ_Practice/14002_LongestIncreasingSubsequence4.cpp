#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000
using namespace std;

int N, cnt = 0;
int A[MAX];
int dp[MAX];
vector<int> ans;

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

		cnt = max(cnt, dp[i]);
	}

	cout << cnt << '\n';

	for (int i = N - 1; i >= 0; --i)
	{
		if (dp[i] == cnt)
		{
			ans.push_back(A[i]);
			--cnt;
		}
	}

	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';
}

int main()
{
	input();
	solve();
	return 0;
}