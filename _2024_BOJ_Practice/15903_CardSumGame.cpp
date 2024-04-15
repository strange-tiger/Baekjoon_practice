#include <iostream>
#include <queue>
#define L long long
using namespace std;

int n, m;
L tmp, answer = 0;
priority_queue<L, vector<L>, greater<L>> pq;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while(n--)
	{
		cin >> tmp;
		pq.push(tmp);
	}
}

void solve()
{
	while (m--)
	{
		tmp = pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();
		pq.push(tmp);
		pq.push(tmp);
	}

	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}

	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}