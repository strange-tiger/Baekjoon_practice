#include <iostream>
#include <stack>
using namespace std;

int N, num;
int A_cnt[1000001] = { 0 };
stack<int> A;
stack<int> A_max;
stack<int> NGF;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		++A_cnt[num];
		A.push(num);
	}
}

void solve()
{
	while (!A.empty())
	{
		if (A_max.empty())
			NGF.push(-1);
		else if (A_cnt[A_max.top()] > A_cnt[A.top()])
			NGF.push(A_max.top());
		else if (A_cnt[A_max.top()] <= A_cnt[A.top()])
		{
			A_max.pop();
			continue;
		}
		A_max.push(A.top());
		A.pop();
	}

	while (!NGF.empty())
	{
		cout << NGF.top() << ' ';
		NGF.pop();
	}
}

int main()
{
	input();
	solve();
	return 0;
}