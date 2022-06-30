// small world effect
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int N, M;

int bfs(int s, int e)
{
	bool isVisited[101] = { false };

	queue<int> q;
	q.push(s);
	isVisited[s] = true;

	int cnt = 0;
	while (!q.empty())
	{
		const int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int ver = q.front();
			q.pop();

			if (ver == e)
				return cnt;

			for (int next : graph[ver])
			{
				if (!isVisited[next])
				{
					q.push(next);
					isVisited[next] = true;
				}
			}
		}

		++cnt;
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	int min = N * N;
	int minPerson = 1;
	for (int i = 1; i <= N; ++i)
	{
		int baconNum = 0;
		for (int j = 1; j <= N; ++j)
		{
			baconNum += bfs(i, j);
		}

		if (min > baconNum)
		{
			min = baconNum;
			minPerson = i;
		}
	}

	cout << minPerson;
}