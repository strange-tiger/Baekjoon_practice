#include <iostream>
#include <stack>
using namespace std;
using L = long long;

L GCD(L a, L b)
{
	while (b % a != 0)
	{
		L temp;
		b %= a;
		temp = a;
		a = b;
		b = temp;
	}

	return a;
}

int N;
L num[100];
L check[99];
L M[98];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	L gcd = 1000000001;
	if (N > 2)
	{
		for (int i = 0; i < N; ++i)
		{
			cin >> num[i];

			if (i > 0)
			{
				if (num[i - 1] < num[i])
					check[i - 1] = num[i] - num[i - 1];
				else
					check[i - 1] = num[i - 1] - num[i];
			}

			if (i > 1)
			{
				if (check[i - 2] < check[i - 1])
					M[i - 2] = GCD(check[i - 2], check[i - 1]);
				else
					M[i - 2] = GCD(check[i - 1], check[i - 2]);

				if (gcd > M[i - 2])
					gcd = M[i - 2];
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; ++i)
		{
			cin >> num[i];
		}
		
		if (num[0] < num[1])
			M[0] = num[1] - num[0];
		else
			M[0] = num[0] - num[1];
		
		gcd = M[0];
	}

	int result = 2;
	stack<int> reverse;
	while (result < gcd / result)
	{
		if (gcd % result == 0)
		{
			cout << result << " ";
			reverse.push(gcd / result);
		}
		++result;
	}

	if (result * result == gcd)
		cout << result << " ";

	while (!reverse.empty())
	{
		cout << reverse.top() << " ";
		reverse.pop();
	}

	cout << gcd;

	return 0;
}

#pragma region 최서연_코드
/*
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

long gcd(int a, int b)
{
	if (b == 1 || b == 0)
	{
		return a;
	}

	if (a % b == 0)
	{
		return b;
	}

	return gcd(b, a % b);
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<long> nums;
	long temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%ld", &temp);
		nums.push_back(temp);
	}

	long min = 1000000001, max = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long tempDiffer = abs(nums[i] - nums[j]);

			if (tempDiffer < min && tempDiffer != 0)
			{
				min = tempDiffer;
			}

			if (tempDiffer > max)
			{
				max = tempDiffer;
			}
		}
	}

	long result = gcd(max, min);

	if (min == 1000000001)
	{
		result = nums[0];
	}

		std::vector<long> resultList;

	for (long i = 2; i <= sqrt(result); ++i)
	{
		if (result % i == 0)
		{
			resultList.push_back(i);
			if (i != (result / i))
			{
				resultList.push_back(result/i);
			}
		}
	}

	resultList.push_back(result);

	std::sort(resultList.begin(), resultList.end());

	for (int i = 0; i < resultList.size(); ++i)
	{
		printf("%d ", resultList[i]);
	}

	return 0;
}
*/
#pragma endregion