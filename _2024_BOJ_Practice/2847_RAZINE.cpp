#include <iostream>
using namespace std;

int N, answer = 0;
int score[100] = { 0 };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> score[i];
}

int diff;
void solve()
{
	for (int i = N - 2; i >= 0; --i)
	{
		if (score[i + 1] <= score[i])
		{
			diff = score[i] - score[i + 1] + 1;
			score[i] = score[i + 1] - 1;
			answer += diff;
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