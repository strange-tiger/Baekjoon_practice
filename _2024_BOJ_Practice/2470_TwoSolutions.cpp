#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int ans[2];
int sol[100000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> sol[i];
	sort(sol, sol + N);
}

void solve()
{
	int tmp, acid = 0, alkali = N - 1, ph = 2e9;;
	while (acid < alkali)
	{
		tmp = sol[acid] + sol[alkali];
		if (ph > abs(tmp))
		{
			ph = abs(tmp);
			ans[0] = sol[acid];
			ans[1] = sol[alkali];
		}

		if (tmp < 0)
			++acid;
		else
			--alkali;
	}

	cout << ans[0] << ' ' << ans[1];
}

int main()
{
	input();
	solve();
	return 0;
}