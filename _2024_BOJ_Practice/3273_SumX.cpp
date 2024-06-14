#include <iostream>
#include <algorithm>
using namespace std;

int n, x, ans = 0;
int seq[100000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	cin >> x;
}

void solve()
{
	int s = 0, e = n - 1, tmp;

	sort(seq, seq + n);

	while (s < e)
	{
		tmp = seq[s] + seq[e];
		if (tmp == x)
		{
			++ans;
			++s;
			--e;
		}
		else if (tmp < x)
			++s;
		else
			--e;
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}