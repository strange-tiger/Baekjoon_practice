#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int N;
int sX, sY;
int sharkSize = 2;
int fishNum = 0;
int eatCnt = 0;
int answer = 0;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[20][20];
int cnt[20][20] = { 0 };
bool eat = false;

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

			if (map[i][j] > 0 && map[i][j] < 9)
			{
				++fishNum;
			}
			else if (map[i][j] == 9)
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
	memset(cnt, 0, sizeof(cnt));
	queue<pair<int, int>> q;

	eat = false;
	q.push({ sX, sY });

	int x, y, nx, ny;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (fishNum == 0)
			return;

		for (int i = 0; i < 4; ++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (cnt[ny][nx] != 0)
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
				sX = nx;
				sY = ny;

				eat = true;

				map[ny][nx] = 0;
				answer += cnt[y][x] + 1;
				
				++eatCnt;
				--fishNum;

				if (eatCnt == sharkSize)
				{
					++sharkSize;
					eatCnt = 0;
				}

				return;
			}
		}
	}

	return;
}

void solve()
{
	do
	{
		bfs();
	}
	while (eat);

	cout << answer;
}

int main()
{
	input();
	
	solve();

	return 0;
}