#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

bool cmp(int a, int b)
{
	return a > b;
}

void dfs()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisited[1001] = { false };

	// 2. DFS�� ����� ������ �����.
	stack<int> st; // ���ÿ��� ������ �湮�� ������ ����ȴ�.
	st.push(V); // ù��°�� �湮�� ����
	// isVisited[V] = true;

	// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (!st.empty()) // ������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		int node = st.top();
		st.pop();
		if (!isVisited[node])
		{
			cout << node << ' ';
		}
		isVisited[node] = true;
		// cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node]) // range-based for loop
		{
			if (!isVisited[nextNode])
			{
				st.push(nextNode);
			}
		}
	}
	cout << '\n';
}

void bfs()
{
	// 1. �湮 ���θ� �����ؾ� �Ѵ�.
	bool isVisited[1001] = { false };

	// 2. BFS�� ����� ť�� �����.
	queue<int> q; // ť���� ������ �湮�� ������ ����ȴ�.
	q.push(V); // ù��°�� �湮�� ����
	isVisited[V] = true;

	// 3. �� �̻� �湮�� ������ ���� ������ �湮�Ѵ�.
	while (!q.empty()) // ������ ����ִٸ� ��� ������ �湮�� ���̴�.
	{
		// 3-1. ������ �湮�Ѵ�.
		int node = q.front();
		q.pop();
		cout << node << ' ';

		// 3-2. �������� �湮�� ������ ã�´�.
		for (int nextNode : graph[node]) // range-based for loop
		{
			if (!isVisited[nextNode])
			{
				q.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. �׷��� ����
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. ���� �������� �湮��Ű�� ���� ����
	for (int i = 0; i < N; ++i)
		sort(graph[i].begin(), graph[i].end(), cmp);
	// 3. Ž�� : DFS&BFS
	dfs();
	// 2. ���� �������� �湮��Ű�� ���� ����
	for (int i = 0; i < N; ++i)
		sort(graph[i].begin(), graph[i].end());
	// 3. Ž�� : DFS&BFS
	bfs();

	return 0;
}