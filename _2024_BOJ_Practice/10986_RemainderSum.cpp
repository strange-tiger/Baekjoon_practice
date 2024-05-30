#include <iostream>
#define L long long
using namespace std;

L N, M, cnt = 0;
L tmp, sum = 0;
L mod[1001] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		sum += tmp;
		++mod[sum % M];
	}
}

void solve()
{
	cnt += mod[0];
	for (int i = 0; i <= M; ++i)
		cnt += mod[i] * (mod[i] - 1) / 2;

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}