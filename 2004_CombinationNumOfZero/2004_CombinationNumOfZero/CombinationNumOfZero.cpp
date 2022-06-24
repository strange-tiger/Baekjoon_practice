#include <iostream>

int ComCntDiv(int N, int M, int div)
{
	int cnt = 0;

	if (N < div || N <= M)
	{
		return 0;
	}
	else
	{
		int temp = N;
		if (temp % div == 0)
		{
			while (temp % div == 0)
			{
				cnt++;
				temp /= div;
			}
		}

		temp = N - M;
		if (temp % div == 0)
		{
			while (temp % div == 0)
			{
				cnt--;
				temp /= div;
			}
		}

		cnt += ComCntDiv(N - 1, M, div);
		return cnt;
	}
}

int N, M;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;

	int twoCnt = ComCntDiv(N, M, 2);
	int fiveCnt = ComCntDiv(N, M, 5);

	int result = (twoCnt > fiveCnt) ? fiveCnt : twoCnt;
	std::cout << result;

	return 0;
}