#include <iostream>
using namespace std;

int N, M;
int i, j;
int sum[100001] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int k = 1; k <= N; ++k)
	{
		cin >> sum[k];
		sum[k] += sum[k - 1];
	}

	while (M--)
	{
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}

	return 0;
}