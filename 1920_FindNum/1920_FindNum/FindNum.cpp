#include <iostream>
#include <algorithm>

int arr[100000];

bool bs(int s, int e, int num)
{
	int middle;
	
	middle = (s + e) / 2;

	if (arr[middle] == num)
	{
		return true;
	}
	else if (s == e)
	{
		return false;
	}
	else if (arr[middle] < num)
	{
		s = middle + 1;
	}
	else if (arr[middle] > num)
	{
		e = middle;
	}

	return bs(s, e, num);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr + N);

	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int num;
		std::cin >> num;

		bool isExist = bs(0, N - 1, num);
		
		std::cout << (isExist ? "1\n" : "0\n");
	}

	return 0;
}