#include <iostream>
#include <algorithm>

int card[500000];

bool bs(int s, int e, int num)
{
	int middle;

	middle = (s + e) / 2;

	if (card[middle] == num)
	{
		return true;
	}
	else if (s == e)
	{
		return false;
	}
	else if (card[middle] < num)
	{
		s = middle + 1;
	}
	else if (card[middle] > num)
	{
		e = middle;
	}

	return bs(s, e, num);
}

int N, M;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> card[i];
	}
	std::sort(card, card + N);

	std::cin >> M;
	int num;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> num;

		std::cout << bs(0, N - 1, num) << ' ';
	}

	return 0;
}