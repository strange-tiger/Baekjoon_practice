#include <iostream>
#define MAX 1000001
using namespace std;

int N;
int players[100001];
int scores[MAX] = { 0 };
bool cards[MAX] = { false };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> players[i];
		cards[players[i]] = true;
	}
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = players[i] * 2; j < MAX; j += players[i])
		{
			if (cards[j])
			{
				++scores[players[i]];
				--scores[j];
			}
		}
	}

	for (int i = 0; i < N; ++i)
		cout << scores[players[i]] << ' ';
}

int main()
{
	input();
	solve();
	return 0;
}