#include <iostream>
using namespace std;

int N;
int Tshirts[6];
int T, P;
int ans[3] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < 6; ++i)
		cin >> Tshirts[i];
	cin >> T >> P;
}

void solve()
{
	for (int i = 0; i < 6; ++i)
	{
		ans[0] += Tshirts[i] / T;

		if (Tshirts[i] % T)
			++ans[0];
	}
	
	ans[1] = N / P;
	ans[2] = N % P;

	cout << ans[0] << '\n' << ans[1] << ' ' << ans[2];
}

int main()
{
	input();
	solve();
	return 0;
}