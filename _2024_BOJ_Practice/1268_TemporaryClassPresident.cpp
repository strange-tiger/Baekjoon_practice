#include <iostream>
using namespace std;

int N, ans, cnt, prevCnt;
int arr[1000][5] = { 0 };
bool check[1000][1000] = { false };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 5; ++j)
			cin >> arr[i][j];
}

void solve()
{

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < N - 1; ++j)
			for (int k = j + 1; k < N; ++k)
				if (arr[j][i] == arr[k][i])
					check[j][k] = check[k][j] = true;

	prevCnt = -1;
	for (int i = 0; i < N; ++i)
	{
		cnt = 0;

		for (int j = 0; j < N; ++j)
			if (check[i][j])
				++cnt;

		if (cnt > prevCnt)
		{
			ans = i + 1;
			prevCnt = cnt;
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