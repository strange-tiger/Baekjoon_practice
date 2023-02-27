#include <iostream>
using namespace std;

int n;
int Max = 0;
int sum[500][501] = { 0 };

int main(void)
{
	cin >> n;

	cin >> sum[0][0];

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> sum[i][j];

			if (j == 0)
				sum[i][j] += sum[i - 1][j];
			else if (j == i)
				sum[i][j] += sum[i - 1][j - 1];
			else
				sum[i][j] += max(sum[i - 1][j], sum[i - 1][j - 1]);
		}
	}

	for (int i = 0; i < n; ++i)
		if (Max < sum[n - 1][i])
			Max = sum[n - 1][i];

	cout << Max;

	return 0;
}