#include <iostream>
using namespace std;

int N, ans = 0, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int tmp = N;

	while (tmp > 0)
	{
		tmp /= 10;
		++cnt;
	}

	for (int i = 1; i < cnt; ++i)
	{
		tmp = 9;
		for (int j = 1; j < i; ++j)
			tmp *= 10;

		ans += tmp * i;
	}

	tmp = 1;
	for (int i = 1; i < cnt; ++i)
		tmp *= 10;

	ans += (N - tmp + 1) * cnt;

	cout << ans;

	return 0;
}