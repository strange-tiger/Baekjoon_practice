#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int N, K;
int ver, dist;
int parent[MAX];
bool isVisited[MAX] = { false };
vector<int> course;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;


int bfs()
{
	heap.push({ 0, N });

	while (!heap.empty())
	{
		dist = heap.top().first;
		ver = heap.top().second;
		heap.pop();

		if (ver == K)
			return dist;

		for (int nxt : {ver - 1, ver + 1, ver * 2})
		{
			if (nxt < 0 || nxt >= MAX)
				continue;

			if (!isVisited[nxt])
			{
				isVisited[nxt] = true;
				heap.push({ dist + 1, nxt });
				parent[nxt] = ver;
			}
		}
	}
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i <= N; ++i)
		parent[i] = -1;
}

void solve()
{
	int time = bfs();
	cout << time << '\n';

	course.push_back(K);
	while (course.back() != N)
		course.push_back(parent[course.back()]);

	while (!course.empty())
	{
		cout << course.back() << ' ';
		course.pop_back();
	}
}

int main()
{
	input();
	solve();
	return 0;
}