#include <iostream>
#define MOD 1000
#define ll long long
using namespace std;

int N, i, j, k;
ll B;
ll A[5][5];
ll ans[5][5];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			cin >> A[i][j];
		ans[i][i] = 1; // 단위행렬
	}
}

void MatrixMultiply(ll a[5][5], ll b[5][5])
{
	ll tmp[5][5] = { 0 };

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			for (k = 0; k < N; ++k)
				tmp[i][j] += a[i][k] * b[k][j];
			tmp[i][j] %= 1000;
		}
	}

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			a[i][j] = tmp[i][j];
}

void solve()
{
	while (B > 0)
	{
		if (B % 2 == 1)
			MatrixMultiply(ans, A);
		MatrixMultiply(A, A);
		B /= 2;
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}


int main()
{
	input();
	solve();
	return 0;
}