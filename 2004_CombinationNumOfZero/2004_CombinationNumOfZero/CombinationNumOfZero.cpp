#include <iostream>
using namespace std;
using L = unsigned long long;

L ComCntDiv(L N, L M, L div)
{
	L cnt = 0;

	for (L i = div; N / i >= 1; i *= div)
	{
		cnt += N / i;
	}

	for (L i = div; M / i >= 1; i *= div)
	{
		cnt -= M / i;
	}

	for (L i = div; (N - M) / i >= 1; i *= div)
	{
		cnt -= (N - M) / i;
	}

	return cnt;
}

L N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	L twoCnt = ComCntDiv(N, M, 2);
	L fiveCnt = ComCntDiv(N, M, 5);

	L result = (twoCnt > fiveCnt) ? fiveCnt : twoCnt;
	cout << result;

	return 0;
}