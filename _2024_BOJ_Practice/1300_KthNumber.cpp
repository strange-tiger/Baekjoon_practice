#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
}

int count(int num)
{
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
		cnt += min(num / i, N);
	return cnt;
}

void solve()
{
	long long lo = 1, hi = N * N, mid;

	while (lo + 1 < hi)
	{
		mid = (lo + hi) / 2;

		if (count(mid) >= K)
			hi = mid;
		else
			lo = mid;
	}

	cout << hi;
}

int main()
{
	input();
	solve();
	return 0;
}