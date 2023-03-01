#include <iostream>
using namespace std;

int n;
int Max = 0;
int sum[10000];
int wine[10000];
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> wine[i];
		sum[i] = wine[i];
	}

	sum[1] += sum[0];
	sum[2] += max(wine[0], wine[1]);

	Max = max(sum[2], max(sum[1], sum[0]));

	for (int i = 3; i < n; ++i)
	{
		sum[i] += max(sum[i - 2], wine[i - 1] + sum[i - 3]);

		if (Max < sum[i])
			Max = sum[i];
	}

	cout << Max;

	return 0;
}