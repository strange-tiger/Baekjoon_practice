#include <iostream>
#include <deque>
using namespace std;

int N, temp, i;
deque<pair<int, int>> balloon;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (i = 0; i < N; ++i)
	{
		cin >> temp;
		balloon.push_back({ temp, i + 1 });
	}

	while (1)
	{
		temp = balloon.front().first;
		cout << balloon.front().second << ' ';
		balloon.pop_front();

		if (balloon.empty())
			break;

		if (temp > 0)
		{
			for (i = 1; i < temp; ++i)
			{
				balloon.push_back(balloon.front());
				balloon.pop_front();
			}
		}
		else
		{
			for (i = temp; i < 0; ++i)
			{
				balloon.push_front(balloon.back());
				balloon.pop_back();
			}
		}
	}

	return 0;
}