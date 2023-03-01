#include <iostream>
using namespace std;

int n;
int sum[10001];
int wine[10001];
int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> wine[i];
		sum[i] = wine[i];
	}

	sum[0] = 0;
	sum[2] = sum[1] + wine[2];
	for (int i = 3; i <= n; ++i)
	{
		sum[i] += max(sum[i - 2], wine[i - 1] + sum[i - 3]);
		sum[i] = max(sum[i - 1], sum[i]);
	}

	cout << sum[n];

	return 0;
}