#include <iostream>
#include <stack>
using namespace std;

int N;
int order;
stack<int> s;
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
			s.push(order);
			break;
		case 2:
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
			break;
		case 3:
			cout << s.size() << '\n';
			break;
		case 4:
			if (s.empty())
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
			break;
		case 5:
			if (s.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << s.top() << '\n';
			}
			break;
		}
	}

	return 0;
}