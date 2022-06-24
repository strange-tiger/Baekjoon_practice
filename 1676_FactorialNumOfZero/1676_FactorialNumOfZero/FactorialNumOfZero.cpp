#include <iostream>

int FacCntDiv(int N, int div)
{
	int cnt = 0;
	
	if (N < div)
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
		cnt += FacCntDiv(N - 1, div);
		return cnt;
	}
}

int N;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;

	int twoCnt = FacCntDiv(N, 2);
	int fiveCnt = FacCntDiv(N, 5);

	int result = (twoCnt > fiveCnt) ? fiveCnt : twoCnt;
	std::cout << result;

	return 0;
}