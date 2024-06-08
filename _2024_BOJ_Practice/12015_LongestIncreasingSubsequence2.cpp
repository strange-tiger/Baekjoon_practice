#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int N, ans = 0, idx;
int A[MAX];
int X[MAX] = { 0 };


void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		if (A[i] > X[ans])
		{
			++ans;
			X[ans] = A[i];
		}
		else
		{
			idx = upper_bound(X, X + i, A[i]) - X - 1;
			X[idx] = min(X[idx], A[i]);
		}
	}

	cout << ans;
}

int main()
{
	input();
	solve();
	return 0;
}