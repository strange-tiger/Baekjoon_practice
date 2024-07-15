#include <iostream>
#include <set>
using namespace std;

int T, N, M, tmp;
set<int> note;

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		note.insert(tmp);
	}
	
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp;
		cout << note.count(tmp) << '\n';
	}

	note.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		solve();
	}
	return 0;
}