#include <iostream>
using namespace std;

int N, M;
int num[100001] = { 0, };
int i, j;
int sum = 0;

int main()
{
	cin >> N >> M;

	for (int k = 0; k < N; ++k)
		cin >> num[k];

	while (M--)
	{
		sum = 0;
		cin >> i >> j;

		for (i; i <= j; ++i)
			sum += num[i - 1];

		cout << sum << endl;
	}

	return 0;
}