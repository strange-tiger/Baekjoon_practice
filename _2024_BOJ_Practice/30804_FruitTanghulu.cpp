#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, cnt = 0;
int s, e;
int S[200000];
int num[10] = { 0 };
set<int> kind;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> S[i];
}

void solve()
{
	while (e < N)
	{
		if (num[S[e]] == 0)
			kind.insert(S[e]);
		++num[S[e]];

		if (kind.size() > 2)
		{
			if (--num[S[s]] == 0)
				kind.erase(S[s]);
			++s;
		}

		cnt = max(cnt, e - s + 1);
		++e;
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}