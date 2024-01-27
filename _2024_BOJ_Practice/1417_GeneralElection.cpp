#include <iostream>
#include <queue>
using namespace std;

int N, dasom, temp;
int cnt = 0;
priority_queue<int> candidate;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> dasom;

	while(--N)
	{
		cin >> temp;
		candidate.push(temp);
	}

	while (!candidate.empty() && dasom <= candidate.top())
	{
		++dasom;
		++cnt;
		temp = candidate.top() - 1;
		candidate.pop();
		candidate.push(temp);
	}

	cout << cnt;

	return 0;
}