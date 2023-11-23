#include <iostream>
using namespace std;

int N, M;
int i, j, temp;
int sum[100001] = { 0, };

int main()
{
	cin >> N >> M;

	sum[0] = 0;

	for (int k = 1; k <= N; ++k)
	{
		cin >> temp;
		sum[k] = temp + sum[k - 1];
	}

	while (M--)
	{
		cin >> i >> j;
		temp = sum[j] - sum[i - 1];
		cout << temp << endl;
	}

	return 0;
}