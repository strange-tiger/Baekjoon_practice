#include <iostream>
#include <deque>
using namespace std;

deque<int> tree[100'000];
int parent[100'000] = { 0 };
int N;
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

	deque<int> leaf;
	while (!tree[1].empty())
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < leaf.size(); ++j)
			{
				for (int k = 0; k < tree[i].size(); ++k)
				{
					if (tree[i][k] == leaf[j])
					{
						tree[i].erase(tree[i].begin() + k);
					}
				}
			}
			
			if (tree[i].size() == 1)
			{
				parent[i] = tree[i].front();
				leaf.push_back(i);
			}
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}