#include <iostream>
#include <algorithm>
using namespace std;

int N;
int pos[200001];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> pos[i];
}

void solve()
{
	sort(pos, pos + N);
	cout << pos[(N - 1) / 2];
}

int main()
{
	input();
	solve();
	return 0;
}