#include <iostream>
#include <algorithm>
#define A 65
using namespace std;

int R, C, answer = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char map[20][20];
bool alpha[26] = { false };

void Input()
{
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> map[i][j];

	alpha[(int)map[0][0] - A] = true;
}

void dfs(int x, int y, int cnt)
{
	answer = max(answer, cnt);

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < C && ny >= 0 && ny < R)
		{
			int ch = (int)map[ny][nx] - A;
			
			if (!alpha[ch])
			{
				alpha[ch] = true;

				dfs(nx, ny, cnt + 1);
				
				alpha[ch] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();

	dfs(0, 0, 1);

	cout << answer;

	return 0;
}