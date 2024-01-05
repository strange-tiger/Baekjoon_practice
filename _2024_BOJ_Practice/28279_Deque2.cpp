#include <iostream>
#include <deque>
using namespace std;

int N;
int order;
deque<int> d;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--)
	{
		cin >> order;

		switch (order)
		{
		case 1:
			cin >> order;
			d.push_front(order);
			break;
		case 2:
			cin >> order;
			d.push_back(order);
			break;
		case 3:
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << d.front() << '\n';
				d.pop_front();
			}
			break;
		case 4:
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << d.back() << '\n';
				d.pop_back();
			}
			break;
		case 5:
			cout << d.size() << '\n';
			break;
		case 6:
			if (d.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
			break;
		case 7:
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << d.front() << '\n';
			}
			break;
		case 8:
			if (d.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << d.back() << '\n';
			}
			break;
		}
	}

	return 0;
}