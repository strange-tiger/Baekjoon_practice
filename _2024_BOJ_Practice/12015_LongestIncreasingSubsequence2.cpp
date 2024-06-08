#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int N, tmp, idx;
vector<int> A, ans;

int binarySearch(int k)
{
	int lo = 0, hi = ans.size() - 1, mid;

	while (lo < hi)
	{
		mid = (lo + hi) / 2;

		if (ans[mid] >= k)
			hi = mid;
		else lo = mid + 1;
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
	{
		cin >> tmp;
		A.push_back(tmp);
	}
}

void solve()
{
	ans.push_back(A.front());

	for (int i = 1; i < N; ++i)
	{
		if (A[i] > ans.back())
			ans.push_back(A[i]);
		else
		{
			idx = binarySearch(A[i]);
			ans[idx] = A[i];
		}
	}

	cout << ans.size();
}

int main()
{
	input();
	solve();
	return 0;
}