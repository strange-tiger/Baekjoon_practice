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
	// 1. 방문 여부를 저장해야 한다.
	bool isVisited[1001] = { false };

	// 2. DFS에 사용할 스택을 만든다.
	stack<int> st; // 스택에는 앞으로 방문할 정점이 저장된다.
	st.push(V); // 첫번째로 방문할 정점
	// isVisited[V] = true;

	// 3. 더 이상 방문할 정점이 없을 때까지 방문한다.
	while (!st.empty()) // 스택이 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3-1. 정점을 방문한다.
		int node = st.top();
		st.pop();
		if (!isVisited[node])
		{
			cout << node << ' ';
		}
		isVisited[node] = true;
		// cout << node << ' ';

		// 3-2. 다음으로 방문할 정점을 찾는다.
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
	// 1. 방문 여부를 저장해야 한다.
	bool isVisited[1001] = { false };

	// 2. BFS에 사용할 큐를 만든다.
	queue<int> q; // 큐에는 앞으로 방문할 정점이 저장된다.
	q.push(V); // 첫번째로 방문할 정점
	isVisited[V] = true;

	// 3. 더 이상 방문할 정점이 없을 때까지 방문한다.
	while (!q.empty()) // 스택이 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3-1. 정점을 방문한다.
		int node = q.front();
		q.pop();
		cout << node << ' ';

		// 3-2. 다음으로 방문할 정점을 찾는다.
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

	// 1. 그래프 구성
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. 작은 정점부터 방문시키기 위해 정렬
	for (int i = 0; i < N; ++i)
		sort(graph[i].begin(), graph[i].end(), cmp);
	// 3. 탐색 : DFS&BFS
	dfs();
	// 2. 작은 정점부터 방문시키기 위해 정렬
	for (int i = 0; i < N; ++i)
		sort(graph[i].begin(), graph[i].end());
	// 3. 탐색 : DFS&BFS
	bfs();

	return 0;
}