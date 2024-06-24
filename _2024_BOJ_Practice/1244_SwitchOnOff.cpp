#include <iostream>
using namespace std;

int N, M;
int Switch[101];
int students[100][2];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> Switch[i];

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> students[i][0];
		cin >> students[i][1];
	}
}

int turnOnOff(int num)
{
	return (num + 1) % 2;
}

void solve()
{
	int gender, num;
	for (int i = 0; i < M; ++i)
	{
		gender = students[i][0], num = students[i][1];
		if (gender == 1)
		{
			for (int j = num; j <= N; j += num)
				Switch[j] = turnOnOff(Switch[j]);
		}
		else
		{
			int l = num - 1, r = num + 1;
			Switch[num] = turnOnOff(Switch[num]);
			while (l > 0 && r <= N && Switch[l] == Switch[r])
			{
				Switch[l] = turnOnOff(Switch[l]);
				Switch[r] = turnOnOff(Switch[r]);

				--l;
				++r;
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Switch[i] << ' ';

		if (i % 20 == 0)
			cout << '\n';
	}
}

int main()
{
	input();
	solve();
	return 0;
}