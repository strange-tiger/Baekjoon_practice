#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int w[31];
int b[8];
bool dp[31][15001] = { false };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> w[i];

	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> b[i];
}

void makeWeight(int cnt, int weight)
{
	if (cnt > n || dp[cnt][weight] != 0)
		return;
	dp[cnt][weight] = true;

	makeWeight(cnt + 1, weight);
	makeWeight(cnt + 1, weight + w[cnt]);
	makeWeight(cnt + 1, abs(weight - w[cnt]));
}

void solve()
{
	makeWeight(0, 0);

	for (int i = 0; i < m; ++i)
	{
		if (b[i] > 15000)
			cout << "N ";
		else if (dp[n][b[i]])
			cout << "Y ";
		else
			cout << "N ";
	}
}

int main()
{
	input();
	solve();
	return 0;
}