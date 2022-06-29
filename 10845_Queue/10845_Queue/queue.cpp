#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <list>
using namespace std;

int N, num;
string str;
list<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--)
	{
		cin >> str;

		if ("push" == str)
		{
			cin >> num;
			q.push_back(num);
		}
		else if ("pop" == str)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if ("size" == str)
		{
			cout << q.size() << '\n';
		}
		else if ("empty" == str)
		{
			cout << q.empty() << '\n';
		}
		else if ("front" == str)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if ("back" == str)
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
	}

	return 0;
}