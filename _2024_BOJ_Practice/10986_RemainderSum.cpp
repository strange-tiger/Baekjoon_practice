#include <iostream>
using namespace std;

int N, M, cnt = 0;
int tmp, sum = 0;
int mod[1001] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		sum += tmp % M;
		sum %= M;
		++mod[sum];
	}
}

void solve()
{
	for (int i = 0; i <= M; ++i)
		cnt += mod[i] * (mod[i] - 1) / 2;
	cnt += mod[0];

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}