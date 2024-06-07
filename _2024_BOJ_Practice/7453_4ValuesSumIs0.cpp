#include <iostream>
#include <set>
#define MAX 4000
#define L long long
using namespace std;

int n, cnt = 0;
int arr[4][MAX];
L added[2][MAX * MAX];
multiset<L> hashCheck;

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
				added[i][j * n + k] = arr[i * 2][j] + arr[i * 2 + 1][k];
}

void solve()
{
	for (int i = 0; i < n * n; ++i)
		hashCheck.insert(added[0][i]);

	for (int i = 0; i < n * n; ++i)
		cnt += hashCheck.count(-added[1][i]);

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}