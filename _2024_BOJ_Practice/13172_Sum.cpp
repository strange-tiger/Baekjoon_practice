#include <iostream>
#define MOD 1000000007
#define ll long long
using namespace std;

int M;
ll N, S, answer = 0;

ll power(ll n, ll m)
{
	ll result = 1;
	while (m)
	{
		if (m & 1)
			result = result * n % MOD;
		m = m / 2;
		n = n * n % MOD;
	}

	return result;
}

void input()
{
	cin >> M;

	while (M--)
	{
		cin >> N >> S;

		answer += (S * power(N, MOD - 2)) % MOD;
	}
}

int main()
{
	input();
	cout << answer % MOD;
	return 0;
}