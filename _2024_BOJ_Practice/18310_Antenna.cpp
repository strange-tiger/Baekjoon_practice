#include <iostream>
#include <vector>
#include <cmath>
#define MAX 2e9
using namespace std;

int N, answer = MAX, Min = MAX;
vector<int> pos;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		pos.push_back(tmp);
	}
}

void solve()
{
	int sum;
	for (int i : pos)
	{
		sum = 0;

		for (int j : pos)
			sum += abs(i - j);

		if (Min >= sum)
		{
			Min = sum;
			answer = i < answer ? i : answer;
		}
	}

	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}