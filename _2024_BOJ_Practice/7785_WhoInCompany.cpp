#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n;
string name, status;
priority_queue<string> People;
map<string, bool> Log;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	while (n--)
	{
		cin >> name >> status;

		if (status == "enter")
			Log[name] = true;
		else
			Log[name] = false;
	}

	for (pair<string, bool> who : Log)
	{
		if (who.second)
			People.push(who.first);
	}

	while (!People.empty())
	{
		cout << People.top() << '\n';
		People.pop();
	}

	return 0;
}