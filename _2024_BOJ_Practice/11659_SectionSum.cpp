#include <iostream>
using namespace std;

int N, M;
int num[100001] = { 0, };
int i, j, k;
int I, J;
int sum = 0;

int main()
{
	cin >> N >> M;

	for (int k = 0; k < N; ++k)
		cin >> num[k];

	while (M--)
	{
		cin >> i >> j;

		if (sum == 0)
		{
			for (k = i; k <= j; ++k)
				sum += num[k - 1];
		}
		else
		{
			if (i < I)
			{
				for (k = i; k < I; ++k)
					sum += num[k - 1];
			}
			else
			{
				for (k = I; k < i; ++k)
					sum -= num[k - 1];
			}
			
			if (j < J)
			{
				for (k = J; k > j; --k)
					sum -= num[k - 1];
			}
			else
			{
				for (k = j; k > J; --k)
					sum += num[k - 1];
			}
		}
		I = i, J = j;

		cout << sum << endl;
	}

	return 0;
}