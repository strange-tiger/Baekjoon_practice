#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N, num[1001], dp[1001][1001];

int Score(int left, int right, int count)
{
	if (left > right)
		return 0;
	if (dp[left][right] != 0)
		return dp[left][right];

	if (count % 2 == 0)
		return dp[left][right] = max(num[left] + Score(left + 1, right, count + 1), num[right] + Score(left, right - 1, count + 1));
	else
		return dp[left][right] = min(Score(left + 1, right, count + 1), Score(left, right - 1, count + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; ++i)
		{
			cin >> num[i];
		}

		memset(dp, 0, sizeof(dp));
		cout << Score(0, N - 1, 0) << '\n';
	}

	return 0;
}