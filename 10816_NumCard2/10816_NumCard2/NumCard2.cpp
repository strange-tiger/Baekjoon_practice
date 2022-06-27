#include <iostream>
#include <algorithm>

int card[500000];

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
		
		int* lowerBound = std::lower_bound(card, card + N, num);
		int* upperBound = std::upper_bound(card, card + N, num);

		std::cout << upperBound - lowerBound << ' ';
	}

	return 0;
}