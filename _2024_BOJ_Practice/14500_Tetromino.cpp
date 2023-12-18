#include <iostream>
using namespace std;

int N, M;
int Max = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int paper[500][500] = { 0 };
bool isVisited[500][500] = { false };

int tx[4][4] = { {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1} };
int ty[4][4] = { {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1} };

int x, y;
void dfs(int x, int y, int sum, int length)
{
    if (length == 0)
    {
        isVisited[y][x] = true;
        dfs(x, y, paper[y][x], length + 1);
        isVisited[y][x] = false;
    }

    if (length > 3)
    {
        Max = max(sum, Max);
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (!isVisited[ny][nx])
        {
            isVisited[ny][nx] = true;
            dfs(nx, ny, sum + paper[ny][nx], length + 1);
            isVisited[ny][nx] = false;
        }
    }
}

void tShape(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        bool isOut = false;
        int sum = 0;

        for (int j = 0; j < 4; ++j)
        {
            int nx = x + tx[i][j];
            int ny = y + ty[i][j];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            {
                isOut = true;
                continue;
            }

            sum += paper[ny][nx];
        }
        if (!isOut)
        {
            Max = max(sum, Max);
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
        for (int j = 0; j < M; ++j)
            cin >> paper[i][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            dfs(j, i, 0, 0);
            tShape(j, i);
        }
    }

    cout << Max;

    return 0;
}