#include <iostream>
#include <algorithm>
using namespace std;

int N, answer = 0;
int rope[100000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> rope[i];
}

void solve()
{
	sort(rope, rope + N);

	for (int i = 0; i < N; ++i)
		answer = max(answer, (N - i) * rope[i]);
	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}