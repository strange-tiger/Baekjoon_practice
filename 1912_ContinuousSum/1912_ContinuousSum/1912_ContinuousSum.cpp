#include <iostream>
using namespace std;

int n, Max = -1001;
int sum[100000] = { 0 };
int main(void)
{
	cin >> n;

	cin >> sum[0];

	int tmp;
	for (int i = 1; i < n; ++i)
	{
		cin >> tmp;
		sum[i] = sum[i - 1] + tmp;

		if (Max < sum[i])
			Max = sum[i];
	}
		
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (Max < sum[i] - sum[j])
				Max = sum[i] - sum[j];

	cout << Max;

	return 0;
}