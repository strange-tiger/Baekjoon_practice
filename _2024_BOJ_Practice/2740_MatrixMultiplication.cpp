#include <iostream>
using namespace std;

int N, M, K;
int matA[100][100];
int matB[100][100];
int res[100][100] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> matA[i][j];

	cin >> M >> K;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < K; ++j)
			cin >> matB[i][j];
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			for (int k = 0; k < M; ++k)
				res[i][j] += matA[i][k] * matB[k][j];

			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	input();
	solve();
	return 0;
}