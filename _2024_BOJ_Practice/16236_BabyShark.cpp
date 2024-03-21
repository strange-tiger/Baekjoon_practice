#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int sX, sY;
int sharkSize = 2;
int eatCnt = 0;
int answer = 0;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[20][20];
int cnt[20][20] = { 0 };
bool noMom = true;
vector<pair<int, int>> fish;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				sX = j;
				sY = i;
			}
		}
	}
}

void bfs()
{
	memset(cnt, -1, sizeof(cnt));
	fish.clear();
	queue<pair<int, int>> q;

	q.push({ sX, sY });
	cnt[sY][sX] = 0;

	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (cnt[ny][nx] != -1)
				continue;
			
			if (map[ny][nx] > sharkSize)
				continue;
			else if (map[ny][nx] == sharkSize || map[ny][nx] == 0)
			{
				cnt[ny][nx] = cnt[y][x] + 1;
				q.push({ nx, ny });
			}
			else if (map[ny][nx] < sharkSize)
			{
				cnt[ny][nx] = cnt[y][x] + 1;
				fish.push_back({ nx, ny });
				q.push({ nx, ny });
			}
		}
	}

	return;
}

// 물고기 중 위쪽과 왼쪽을 우선하는 문제를 해결하기 위해,
// 물고기의 위치를 벡터에 저장하고 저장된 물고기의 갯수에 따라 
// 가까운 물고기 중 위쪽, 왼쪽을 우선하여 골라 먹는 함수
void chooseFish()
{
	if (fish.size() == 0)
	{
		noMom = false;
		return;
	}
	else if (fish.size() == 1)
	{
		sX = fish.front().first;
		sY = fish.front().second;
		map[sY][sX] = 0;

		++eatCnt;
		answer += cnt[sY][sX];
	}
	else
	{
		int Min = 1e8;
		vector<pair<int, int>> eatenFish;

		for (pair<int, int> Pos : fish)
			Min = min(Min, cnt[Pos.second][Pos.first]);

		for (pair<int, int> Pos : fish)
			if (Min == cnt[Pos.second][Pos.first])
				eatenFish.push_back({ Pos.second, Pos.first });

		if (eatenFish.size() == 1)
		{
			sX = eatenFish.front().second;
			sY = eatenFish.front().first;

			map[sY][sX] = 0;

			++eatCnt;
			answer += cnt[sY][sX];
		}
		else
		{
			sort(eatenFish.begin(), eatenFish.end());
			sX = eatenFish.front().second;
			sY = eatenFish.front().first;

			map[sY][sX] = 0;

			++eatCnt;
			answer += cnt[sY][sX];
		}
	}

	if (eatCnt >= sharkSize)
	{
		eatCnt -= sharkSize;
		++sharkSize;
	}
}

void solve()
{
	while (noMom)
	{
		bfs();
		chooseFish();
	}

	cout << answer;
}

int main()
{
	input();
	
	solve();

	return 0;
}