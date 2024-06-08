#include <iostream>
#define MAX 1001
using namespace std;

int N;
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
	int Max = 0;

	for (int i = 0; i < N; ++i)
	{
		dp[i] = A[i];

		for (int j = 0; j < i; ++j)
			if (A[j] < A[i] && dp[i] < dp[j] + A[i])
				dp[i] = dp[j] + A[i];

		Max = Max < dp[i] ? dp[i] : Max;
	}

	cout << Max;
}

int main()
{
	input();
	solve();
	return 0;
}