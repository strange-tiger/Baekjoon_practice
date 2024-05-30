#include <iostream>
using namespace std;

int N, M, cnt = 0;
int mod[1000000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int tmp;
	cin >> mod[0];
	mod[0] %= M;
	for (int i = 1; i < N; ++i)
	{
		cin >> tmp;
		mod[i] = (tmp + mod[i - 1]) % M;
	}
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		if (mod[i] == 0)
			++cnt;
		for (int j = i + 1; j < N; ++j)
			if (mod[i] == mod[j])
				++cnt;
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}