#include <iostream>
#include <algorithm>
#include <stack>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int N, num[100002], ans = 0;
stack<int> s;
void Input()
{
	fastio;

	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> num[i];
	}
}

void Solve()
{
	s.push(0);
	for (int i = 1; i <= N + 1; ++i)
	{
		while (!s.empty() && num[s.top()] > num[i])
		{
			int height = num[s.top()];
			s.pop();
			int width = i - s.top() - 1;
			ans = max(ans, height * width);
		}
		s.push(i);
	}

	cout << ans << '\n';
}

int main()
{
	Input();
	Solve();
	return 0;
}