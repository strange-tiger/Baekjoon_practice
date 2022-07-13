#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, x;
deque<int> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	while (N--)
	{
		cin >> x;
		if (x != 0)
		{
			if (arr.size() == 0)
			{
				arr.push_back(x);
			}
			else if (x >= arr.back())
			{
				arr.push_back(x);
			}
			else
			{
				int n = arr.size();
				while (n > 0 && x < arr[n - 1])
				{
					n--;
				}

				arr.insert(arr.begin() + n, x);
			}
		}
		else if (!arr.empty())
		{
			cout << arr.back() << '\n';
			arr.pop_back();
		}
		else
		{
			cout << x << '\n';
		}
	}

	return 0;
}