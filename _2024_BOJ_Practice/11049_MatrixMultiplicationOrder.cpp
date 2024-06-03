#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;

int N;
int mat[501][2];
int dp[501][501];
int dpMat[501][501][2];

void proj(int m, int n)
{
	dpMat[m][n][0] = mat[m][0];
	dpMat[m][n][1] = mat[n][1];
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> mat[i][0] >> mat[i][1];
		proj(i, i);
	}
}

void solve()
{
	for (int i = 1; i < N; ++i)
	{
		for (int s = 0; s + i < N; ++s)
		{
			int e = s + i;

			dp[s][e] = MAX;

			for (int mid = s; mid < e; ++mid)
			{
				dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid + 1][e] + dpMat[s][mid][0] * dpMat[s][mid][1] * dpMat[mid + 1][e][1]);
			}

			proj(s, e);
		}
	}

	cout << dp[0][N - 1];
}

int main()
{
	input();
	solve();
	return 0;
}