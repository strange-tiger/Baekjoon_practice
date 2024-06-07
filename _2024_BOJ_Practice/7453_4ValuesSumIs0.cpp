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

	for (L i = 0; i < N; ++i)
	{
		L lower = lower_bound(sum[1], sum[1] + N, -sum[0][i]) - sum[1];
		L upper = upper_bound(sum[1], sum[1] + N, -sum[0][i]) - sum[1];

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