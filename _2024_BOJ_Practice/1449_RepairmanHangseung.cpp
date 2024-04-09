#include <iostream>
#include <algorithm>
using namespace std;

int N, L, start, num = 1;
int pipe[1000];

void input()
{
	cin >> N >> L;

	for (int i = 0; i < N; ++i)
		cin >> pipe[i];

	sort(pipe, pipe + N);
	start = pipe[0];
}

void solve()
{
	for (int i = 1; i < N; ++i)
	{
		if (L <= pipe[i] - start)
		{
			++num;
			start = pipe[i];
		}
	}
	cout << num;
}

int main()
{
	input();
	solve();
	return 0;
}