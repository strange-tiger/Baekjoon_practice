#include <iostream>
#include <cmath>
#include <vector>
#define L long long
using namespace std;

int N, cnt = 0;
int prime[4000001] = { 0 };
vector<int> primeSeq;

void getPrime(int num)
{
	for (int i = 2; i <= num; ++i)
		prime[i] = i;

	for (int i = 2; i <= num; ++i)
	{
		if (prime[i] == 0)
			continue;
		else
			primeSeq.push_back(prime[i]);

		if ((L)(i)*i > 2e9)
			continue;

		for (int j = i * i; j <= num; j += i)
		{
			prime[j] = 0;
		}
	}
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	getPrime(N);
}

void solve()
{
	int s = 0, e = 0;
	L sum;

	while (s <= e)
	{
		if (e >= primeSeq.size())
			break;

		sum = 0;

		for (int i = s; i <= e; ++i)
			sum += primeSeq[i];

		if (sum < N)
			++e;
		else if (sum > N)
			++s;
		else
		{
			++cnt;
			++e;
		}
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}