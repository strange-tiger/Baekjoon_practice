#include <iostream>
#define MOD 1000000007
#define L long long
using namespace std;

int N, K;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
}

L power(L n, L m)
{
	L res = 1;
	while (m)
	{
		if (m & 1)
			res = res * n % MOD;
		m /= 2;
		n = n * n % MOD;
	}

	return res;
}

void solve()
{
	if (K == 1 || K == N - 1)
	{
		cout << N % MOD;
		return;
	}
	else if (K == 0 || K == N)
	{
		cout << 1;
		return;
	}

	L a = 1, b = 1, res;

	for (int i = N; i > N - K; --i)
		a = a * i % MOD;
	for (int i = 1; i <= K; ++i)
		b = b * i % MOD;

	res = a * power(b, MOD - 2) % MOD;
	cout << res;
}

int main()
{
	input();
	solve();
	return 0;
}