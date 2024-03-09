#include <iostream>
using namespace std;

int N, i, j;
int house[16][16] = { 0 };
int dp[16][16][3] = { 0 };

// dp[y][x][dir] dir : 0 -> 가로 1 -> 세로 2 -> 대각선
int DP()
{
	dp[0][1][0] = 1;

	for (i = 0; i < N; ++i)
	{
		for (j = 2; j < N; ++j)
		{
			if (!house[i][j])
			{
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

				if (i > 0)
				{
					dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

					if (!house[i][j - 1] && !house[i - 1][j])
						dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
				}
			}
		}
	}

	return dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			cin >> house[i][j];

	cout << DP();

	return 0;
}