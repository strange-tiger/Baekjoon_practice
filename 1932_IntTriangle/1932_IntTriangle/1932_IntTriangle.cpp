#include <iostream>
#include <vector>
using namespace std;

int n, tmp;
int Max = 0;
vector<int> sum[500];

int main(void)
{
	cin >> n;

	cin >> tmp;
	sum[0].push_back(tmp);

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> tmp;

			if (j == 0)
				tmp += sum[i - 1][j];
			else if (j == i)
				tmp += sum[i - 1][j - 1];
			else
				tmp += max(sum[i - 1][j], sum[i - 1][j - 1]);

			sum[i].push_back(tmp);
		}
	}

	for (int i = 0; i < n; ++i)
		if (Max < sum[n - 1][i])
			Max = sum[n - 1][i];

	cout << Max;

	return 0;
}