#include <iostream>
using namespace std;

int N, M, S, E;
int seq[2001];
bool dp[2001][2001];
void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	cin >> M;
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		dp[i][i] = true;

		if (i < N - 1 && seq[i] == seq[i + 1])
			dp[i][i + 1] = true;
		else
			dp[i][i + 1] = false;
	}

	for (int i = 0; i < N - 2; ++i)
		for (int j = i + 2; j < N; ++j)
			if (seq[i] == seq[j] && dp[i + 1][j - 1])
				dp[i][j] = true;

	for (int i = 0; i < M; ++i)
	{
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << '\n';
	}
}

int main()
{
	input();
	solve();
	return 0;
}