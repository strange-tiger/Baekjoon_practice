#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int cnt[1000001] = { 0 };
int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		cnt[i] = cnt[i - 1] + 1;

		if (i % 3 == 0)
		{
			cnt[i] = min(cnt[i], cnt[i / 3] + 1);
		}

		if (i % 2 == 0)
		{
			cnt[i] = min(cnt[i], cnt[i / 2] + 1);
		}
	}

	cout << cnt[N];

	return 0;
}