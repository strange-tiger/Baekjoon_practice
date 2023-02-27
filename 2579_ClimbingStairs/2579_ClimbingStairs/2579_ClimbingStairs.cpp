#include <iostream>
using namespace std;

int n;
int sum[300];
int stairs[300];
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> stairs[i];
		sum[i] = stairs[i];
	}

	sum[1] += sum[0];
	sum[2] += max(stairs[0], stairs[1]);

	for (int i = 3; i < n; ++i)
		sum[i] += max(sum[i - 2], stairs[i - 1] + sum[i - 3]);

	cout << sum[n - 1];

	return 0;
}