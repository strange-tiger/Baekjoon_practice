#include <iostream>
#include <string>
using namespace std;

int N, M, K, MIN;
string board[2000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
		cin >> board[i];
}

void solve()
{
	MIN = 2e6;
	for (int i = 0; i <= N - K; ++i)
	{
		for (int j = 0; j <= M - K; ++j)
		{
			// 왼쪽 위가 하얀색인 경우
			int cnt = 0;
			for (int k = i; k < i + K; ++k)
			{
				for (int l = j; l < j + K; ++l)
				{
					if ((k + l) % 2 == 1 && board[k][l] == 'W')
						++cnt;
					else if ((k + l) % 2 == 0 && board[k][l] == 'B')
						++cnt;

				}
			}

			if (MIN > cnt)
				MIN = cnt;

			// 왼쪽 위가 검은색인 경우
			cnt = 0;
			for (int k = i; k < i + K; ++k)
			{
				for (int l = j; l < j + K; ++l)
				{
					if ((k + l) % 2 == 1 && board[k][l] == 'B')
						++cnt;
					else if ((k + l) % 2 == 0 && board[k][l] == 'W')
						++cnt;

				}
			}

			if (MIN > cnt)
				MIN = cnt;
		}
	}

	cout << MIN;
}

int main()
{
	input();
	solve();
	return 0;
}