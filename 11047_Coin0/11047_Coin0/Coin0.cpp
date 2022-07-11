#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> coins;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	while (N--)
	{
		int price;
		cin >> price;
		coins.push_back(price);
	}

	int num = 0;
	int size = coins.size();
	for (int i = 0; i < size; ++i)
	{
		if (coins[i] >= K || i == size - 1)
		{
			for (int j = i; K != 0; --j)
			{
				num += K / coins[j];
				K %= coins[j];
			}
			
			break;
		}
	}
	

	cout << num << '\n';

	return 0;
}