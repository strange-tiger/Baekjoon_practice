#include <iostream>
#include <queue>
using namespace std;

int N, M;
int x, y;
int meet = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[600][600] = { 0 };
bool isVisited[600][600] = { false };
queue<pair<int, int>> q;
void bfs()
{
	q.push({ y, x });
	isVisited[y][x] = true;

	while (!q.empty())
	{
		x = q.front().second;
		y = q.front().first;
		q.pop();

		int nx, ny;
		for (int i = 0; i < 4; ++i)
		{
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			if (isVisited[ny][nx])
				continue;

			
			isVisited[ny][nx] = true;
			
			if (map[ny][nx] == 'P')
				++meet;
			if (map[ny][nx] != 'X')
				q.push({ ny, nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'I')
			{
				x = j;
				y = i;
			}
		}
	}

	bfs();

	if (meet)
		cout << meet;
	else
		cout << "TT";

	return 0;
}