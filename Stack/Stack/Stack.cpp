#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	list<int> lst;

	int N;
	cin >> N;

	string str;
	while (N--)
	{
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;

			lst.push_back(num);
		}
		else if (str == "pop")
		{
			if (!lst.empty())
			{ 
				cout << lst.back() << '\n';
				lst.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (str == "size")
		{
			cout << lst.size() << '\n';
		}
		else if (str == "empty")
		{
			cout << lst.empty() << '\n';
		}
		else if (str == "top")
		{
			if (!lst.empty())
				cout << lst.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	
	return 0;
}