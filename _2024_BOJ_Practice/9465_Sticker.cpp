#include <iostream>
using namespace std;

int T, n, tmp;
int sticker[2][100000];
int sum[2][100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> n;

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				cin >> sticker[i][j];

		sum[0][0] = sticker[0][0];
		sum[1][0] = sticker[1][0];

		for (int i = 0; i < n; ++i)
		{
			sum[0][i] = max(sum[0][i - 1], sum[1][i - 1]+ sticker[0][i]);
			sum[1][i] = max(sum[1][i - 1], sum[0][i - 1]+ sticker[1][i]);
		}
		
		cout << max(sum[0][n - 1], sum[1][n - 1]) << '\n';
	}

	return 0;
}