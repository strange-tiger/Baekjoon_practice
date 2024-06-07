#include <iostream>
#include <algorithm>
#include <vector>
#define L long long
using namespace std;

int n;
int arr[4001][4];
vector<int> AB, CD;
L cnt = 0;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			AB.push_back(arr[i][0] + arr[j][1]);
			CD.push_back(arr[i][2] + arr[j][3]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
}

void solve()
{
	for (int i = 0; i < AB.size(); ++i)
	{
		int start = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
		int end = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();

		cnt += end - start;
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}