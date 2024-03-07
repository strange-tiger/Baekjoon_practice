#include <iostream>
#include <string>
using namespace std;

int i, j, len1, len2;
int answer = 0;
int dp[4001][4001] = { 0 };
string str1, str2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();

	for (i = 1; i <= len1; ++i)
	{
		for (j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;

				if (answer < dp[i][j])
					answer = dp[i][j];
			}
		}
	}

	cout << answer;

	return 0;
}