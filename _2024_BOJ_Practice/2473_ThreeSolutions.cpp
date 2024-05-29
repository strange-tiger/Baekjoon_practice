#include <iostream>
#include <algorithm>
#define L long long
using namespace std;

L N;
L ans[3];
L sol[5000];

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
	L tmp, acid, alkali, ph = 3e9;
	
	for (int i = 0; i < N - 2; ++i)
	{
		acid = i + 1;
		alkali = N - 1;

		while (acid < alkali)
		{
			tmp = sol[i] + sol[acid] + sol[alkali];
			if (ph > abs(tmp))
			{
				ph = abs(tmp);
				ans[0] = sol[i];
				ans[1] = sol[acid];
				ans[2] = sol[alkali];
			}

			if (tmp < 0)
				++acid;
			else
				--alkali;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}

int main()
{
	input();
	solve();
	return 0;
}