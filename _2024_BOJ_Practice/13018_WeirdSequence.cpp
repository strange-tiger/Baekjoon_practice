// 13018_WeirdSequence.cpp
#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, k;
void Input()
{
	fastio;

	cin >> n >> k;
}

void Solve()
{
	if (n == k)
	{
		cout << "Impossible";
	}
	else if (n == k + 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << i << ' ';
		}
	}
	else
	{
		cout << k + 2 << ' ';
		for (int i = 2; i <= k + 1; ++i)
		{
			cout << i << ' ';
		}
		for (int i = k + 2; i <= n; ++i)
		{
			cout << (i < n ? i + 1 : 1) << ' ';
		}
	}
}

int main()
{
	Input();
	Solve();
	return 0;
}