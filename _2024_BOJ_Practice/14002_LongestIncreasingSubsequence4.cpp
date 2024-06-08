#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N, tmp, idx;
int A[MAX];
vector<int> X, ans;

int binarySearch(int k)
{
	int lo = 0, hi = X.size() - 1, mid;

	while (lo < hi)
	{
		mid = (lo + hi) / 2;

		if (X[mid] >= k)
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
	X.push_back(A[0]);
	ans.push_back(A[0]);

	for (int i = 1; i < N; ++i)
	{
		if (A[i] > X.back())
		{
			X.push_back(A[i]);
			
			for (int j = 0; j < ans.size(); ++j)
				ans[j] = X[j];
			ans.push_back(A[i]);
		}
		else
		{
			idx = binarySearch(A[i]);
			X[idx] = A[i];
		}
	}

	cout << X.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << ' ';
}

int main()
{
	input();
	solve();
	return 0;
}