#include <iostream>
#include <stack>
using namespace std;

int N;
int temp, cnt = 1;
stack<int> space;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		space.push(temp);

		while (!space.empty() && space.top() == cnt)
		{
			++cnt;
			space.pop();
		}
	}

	while (!space.empty())
	{
		if (cnt == space.top())
		{
			++cnt;
			space.pop();
		}
		else
		{
			cout << "Sad" << '\n';
			return 0;
		}
	}
	cout << "Nice" << '\n';

	return 0;
}