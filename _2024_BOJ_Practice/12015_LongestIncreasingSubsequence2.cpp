#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N, idx, ans = 0;
int A[MAX];
int X[MAX];

int binarySearch(int key)
{
	int lo = 0, hi = ans - 1, mid;

	while (lo + 1 < hi)
	{
		mid = (lo + hi) / 2;

		if (X[mid] > key)
			hi = mid;
		else
			lo = mid + 1;
	}

	return hi;
}

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
	X[1] = A[0];
	ans = 1;

	for (int i = 1; i < N; ++i)
	{
		if (A[i] > X[ans])
		{
			X[++ans] = A[i];
		}
		else
		{
			idx = binarySearch(A[i]);
			X[idx] = A[i];
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