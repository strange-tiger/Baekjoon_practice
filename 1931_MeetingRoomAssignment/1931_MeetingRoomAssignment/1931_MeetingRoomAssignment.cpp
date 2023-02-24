#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> meeting;

int N, S, E;
int cnt = 1;
meeting schedule[100000];
int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> S >> E;
		schedule[i].first = E;
		schedule[i].second = S;
	}

	sort(schedule, schedule + N);

	int endTime = 0;
	for (int i = 1; i < N; ++i)
	{
		if (schedule[endTime].first <= schedule[i].second)
		{
			++cnt;
			endTime = i;
		}
	}

	cout << cnt;

	return 0;
}