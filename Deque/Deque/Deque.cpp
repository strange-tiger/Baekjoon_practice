#include <iostream>
#include <list>
#include <string>
using namespace std;

int N;
string str;
list<int> deq;
int main()
{
	cin >> N;

	int num;
	while (N--)
	{
		cin >> str;

		if ("push_front" == str)
		{
			cin >> num;
			deq.push_front(num);
		}
		else if ("push_back" == str)
		{
			cin >> num;
			deq.push_back(num);
		}
		else if ("pop_front" == str)
		{
			if (deq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if ("pop_back" == str)
		{
			if (deq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if ("size" == str)
		{
			cout << deq.size() << '\n';
		}
		else if ("empty" == str)
		{
			cout << deq.empty() << '\n';
		}
		else if ("front" == str)
		{
			if (deq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deq.front() << '\n';
			}
		}
		else if ("back" == str)
		{
			if (deq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deq.back() << '\n';
			}
		}
	}
	return 0;
}