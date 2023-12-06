#include <iostream>
#include <queue>
#include <vector>
#define INF 1000001
using namespace std;

int N, M, X;
int from, to, T;
vector<pair<int, int>> road[1001]; // 그래프 선언, 각 간선과 가중치 저장

vector<int> dijkstra(int start, int num, vector<pair<int, int>> graph[])
{
	vector<int> dist(num + 1, INF); // 거리 저장할 리스트 초기화
	priority_queue<pair<int, int>> heap; // 기본 최대힙. 최소힙처럼 쓰기 위해 거리 부분에 -를 붙여 음수로 다룰 것.

	dist[start] = 0; // 시작점 거리는 0
	heap.push({ 0, start });

	int curDist, curNode, nxtDist, nxtNode;
	while (!heap.empty())
	{
		curDist = -heap.top().first; // 힙에서 꺼내 방문한 정점까지의 거리
		curNode = heap.top().second; // 정점 번호
		heap.pop();

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			nxtDist = curDist + graph[curNode][i].second; // 인접 정점까지의 거리
			nxtNode = graph[curNode][i].first; // 인접 정점 번호

			if (nxtDist < dist[nxtNode]) // 지금 계산이 더 작다면
			{
				dist[nxtNode] = nxtDist;
				heap.push({ -nxtDist, nxtNode });
			}
		}
	}

	return dist;
}

// 집에서 파티까지 거리를 구하는 함수
vector<int> homeToParty(int party, int num, vector<pair<int, int>> graph[])
{
	vector<int> dist(num + 1, INF);
	priority_queue<pair<int, int>> heap;

	dist[0] = 0; // 문제에서 0번 정점이 없으므로 제외
	dist[party] = 0;

	
	int curDist, curNode, nxtDist, nxtNode;
	for (int k = 1; k <= num; ++k) // 각 정점을 기준으로 파티 정점까지의 최단거리를 구하기 위해 각 정점 기준 거리 배열을 구한다.
	{
		if (k == party)
			continue;
		
		vector<int> tempDist(num + 1, INF);

		tempDist[0] = 0;
		tempDist[k] = 0;
		heap.push({ 0, k });

		while (!heap.empty())
		{
			curDist = -heap.top().first;
			curNode = heap.top().second;
			heap.pop();

			for (int i = 0; i < graph[curNode].size(); ++i)
			{
				nxtDist = curDist + graph[curNode][i].second;
				nxtNode = graph[curNode][i].first;

				if (nxtDist < tempDist[nxtNode])
				{
					tempDist[nxtNode] = nxtDist;
					heap.push({ -nxtDist, nxtNode });
				}
			}
		}

		dist[k] = tempDist[party];
	}

	return dist;
}
// 파티에서 집까지 거리를 구하는 함수
vector<int> partyToHome(int party, int num, vector<pair<int, int>> graph[])
{
	vector<int> dist(num + 1, INF);
	priority_queue<pair<int, int>> heap;

	dist[0] = 0; // 문제에서 0번 정점이 없으므로 제외
	dist[party] = 0;
	heap.push({ 0, party });

	int curDist, curNode, nxtDist, nxtNode;
	while (!heap.empty())
	{
		curDist = -heap.top().first;
		curNode = heap.top().second;
		heap.pop();

		for (int i = 0; i < graph[curNode].size(); ++i)
		{
			nxtDist = curDist + graph[curNode][i].second;
			nxtNode = graph[curNode][i].first;

			if (nxtDist < dist[nxtNode])
			{
				dist[nxtNode] = nxtDist;
				heap.push({ -nxtDist, nxtNode });
			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> X;

	while (M--)
	{
		cin >> from >> to >> T;
		road[from].push_back({ to, T });
	}

	vector<int> distToGo = homeToParty(X, N, road);
	vector<int> distToBack = partyToHome(X, N, road);

	for (int i = 1; i < distToGo.size(); ++i)
		distToGo[i] += distToBack[i];

	int max = 0;
	for (int now : distToGo)
		if (now > max)
			max = now;

	cout << max;

	return 0;
}