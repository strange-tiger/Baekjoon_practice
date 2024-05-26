#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lenA, lenB;
int dp[1001][1001];
string A, B;
string ans = "";

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;
	lenA = A.length();
	lenB = B.length();
}

void DP()
{
	for (int i = 1; i <= lenA; ++i)
	{
		for (int j = 1; j <= lenB; ++j)
		{
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

void backtrack()
{
	int a = lenA, b = lenB;

	while (a > 0 && b > 0)
	{
		if (dp[a][b] > dp[a - 1][b] && dp[a - 1][b] == dp[a - 1][b - 1] && dp[a - 1][b] == dp[a][b - 1])
		{
			ans += A[a - 1];
			--a;
			--b;
		}
		else if (dp[a][b] == dp[a - 1][b] && dp[a - 1][b] > dp[a][b - 1])
			--a;
		else if (dp[a][b] == dp[a][b - 1] && dp[a - 1][b] < dp[a][b - 1])
			--b;
		else
			--b;
	}

	reverse(ans.begin(), ans.end());
}

void solve()
{
	DP();
	backtrack();
	if (dp[lenA][lenB] != 0)
		cout << dp[lenA][lenB] << '\n' << ans;
	else
		cout << 0;
}

int main()
{
	input();
	solve();	
	return 0;
}