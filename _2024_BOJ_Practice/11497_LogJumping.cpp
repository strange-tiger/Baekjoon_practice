#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int T, N, answer;
int L[10000];
priority_queue<int> heap;

void input()
{
	cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		heap.push(tmp);
	}
}

void solve()
{
	int tmp;
	for (int i = 0; i < N; ++i)
	{
		tmp = heap.top();
		heap.pop();

		if (i % 2)
			L[N - 1 - i / 2] = tmp;
		else
			L[i / 2] = tmp;
	}

	answer = 0;
	for (int i = 0; i < N - 1; ++i)
		answer = max(answer, abs(L[i] - L[i + 1]));
	answer = max(answer, abs(L[N - 1] - L[0]));

	cout << answer << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		input();
		solve();
	}

	return 0;
}