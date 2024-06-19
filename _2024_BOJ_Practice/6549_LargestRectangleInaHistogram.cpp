#include <iostream>
using namespace std;

int n;
int h[100001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n, n != 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> h[i];
		}
	}
}

// https://www.acmicpc.net/problem/6549