#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt = 0;
int u, v;
bool node[1001] = { false };
vector<int> connectedList[1001];
queue<int> bfsQueue;
void bfs(int n)
{
	node[n] = true;
	bfsQueue.push(n);

	while (!bfsQueue.empty())
	{
		n = bfsQueue.front();
		bfsQueue.pop();

		for (int i : connectedList[n])
		{
			if (!node[i])
			{
				node[i] = true;
				bfsQueue.push(i);
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v;

		connectedList[u].push_back(v);
		connectedList[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!node[i])
		{
			bfs(i);
			++cnt;
		}
	}

	cout << cnt;

	return 0;
}