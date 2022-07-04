#include <iostream>
#include <deque>
using namespace std;

deque<int> tree[100'001];
int parent[100'001] = { 0 };
int N;

void dfs(int ver)
{
	for (int next : tree[ver])
	{
		if (parent[next] == 0)
		{
			parent[next] = ver;
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int s, e;
		cin >> s >> e;

		tree[s].push_back(e);
		tree[e].push_back(s);
	}
	parent[1] = 1;
	dfs(1);

	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}
// 진호야 나는 언제나 널 응원한단다 화이팅하자