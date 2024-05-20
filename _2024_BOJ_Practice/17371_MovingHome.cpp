#include <iostream>
using namespace std;

int N;
int Min = 10e9, idx = 0;
int pos[1000][2];

int distance(int a[2], int b[2])
{
	return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
		cin >> pos[i][0] >> pos[i][1];
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		int  Max = -1, maxIdx = 0, tmp;
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
				continue;

			tmp = distance(pos[i], pos[j]);
			if (Max < tmp)
			{
				Max = tmp;
				maxIdx = i;
			}
		}

		if (Min > Max)
		{
			Min = Max;
			idx = maxIdx;
		}
	}

	cout << pos[idx][0] << ' ' << pos[idx][1];
}

int main()
{
	input();
	solve();
	return 0;
}