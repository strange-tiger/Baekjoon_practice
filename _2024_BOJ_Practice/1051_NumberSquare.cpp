#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, ans = 0;
string rect[50];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> rect[i];
}

void solve()
{
	int dif;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < M - j; ++k)
			{
				if (rect[i][j] == rect[i][j + k] && i + k < N && rect[i][j] == rect[i + k][j] && rect[i + k][j] == rect[i + k][j + k])
					ans = max(ans, (k + 1) * (k + 1));
			}
		}
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}