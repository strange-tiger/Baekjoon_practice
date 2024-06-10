#include <iostream>
#include <algorithm>
using namespace std;

long long N, K;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
}

long long count(long long num)
{
	long long cnt = 0;
	for (int i = 1; i <= N; ++i)
		cnt += min(num / i, N);
	return cnt;
}

void solve()
{
	long long lo = 1, hi = N * N, mid;

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;

		if (count(mid) >= K)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	cout << lo;
}

int main()
{
	input();
	solve();
	return 0;
}