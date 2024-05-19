#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int cnt = 0, x, y, tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> tmp;

			if (tmp == 1)
			{
				if (cnt == 0)
				{
					y = i;
					x = j;
					++cnt;
				}
				else
				{
					y = i - y;

					if (x < j)
						x = j - x;
					else
						x = x - j;
				}
			}
		}
	}

	cout << x + y;
	return 0;
}