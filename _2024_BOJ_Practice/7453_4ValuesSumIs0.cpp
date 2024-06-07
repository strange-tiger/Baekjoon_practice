#include <iostream>
#include <algorithm>
#define MAX 4000
#define L long long
using namespace std;

int n, cnt = 0;
int arr[4][MAX];
L sum[2][MAX * MAX];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				sum[i][j * n + k] = arr[i * 2][j] + arr[i * 2 + 1][k];
}

void solve()
{
	int N = n * n;

	sort(sum[1], sum[1] + N);

	for (int i = 0; i < N; ++i)
	{
		int s = 0, e = N - 1, mid;
		int upper, lower;

		while (s + 1 < e)
		{
			mid = (s + e) / 2;

			if (sum[0][i] < -sum[1][mid])
				s = mid;
			else
				e = mid;
		}
		lower = e;

		s = 0, e = N - 1;
		while (s + 1 < e)
		{
			mid = (s + e) / 2;

			if (sum[0][i] <= -sum[1][mid])
				s = mid;
			else
				e = mid;
		}
		upper = e;

		cnt += upper - lower;
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}