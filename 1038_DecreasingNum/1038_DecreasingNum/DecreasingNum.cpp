#include <iostream>
using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	//long long num = 9'876'543'210;
	int digit[10] = { 0 };
	
	while (N)
	{
		++digit[0];

		for (int i = 0; i < 9; ++i)
		{
			if (digit[i + 1] != 0)
			{
				if (digit[i] >= digit[i + 1])
				{
					++digit[i + 1];
					digit[i] = i;
				}
			}

			if (digit[i] == 10)
			{
				digit[i + 1] = i + 1;
				digit[i] = i;
			}
		}

		--N;
	}

	for (int i = 9; i >= 0; --i)
	{
		if (digit[i] != 0 || i == 0)
		{
			if (digit[9] > 9)
			{
				cout << -1;
				break;
			}
			
			for (int j = i; j >= 0; --j)
			{
				cout << digit[j];
			}
			break;
		}
	}

	return 0;
}
