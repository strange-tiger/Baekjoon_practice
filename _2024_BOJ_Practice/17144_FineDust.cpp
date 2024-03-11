#include <iostream>

using namespace std;

int R, C, T;
int total;
int upRow, downRow;
int room[51][51];
int add[51][51];
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;

    bool flag = false;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
            {
                if (!flag)
                {
                    upRow = i;
                    flag = true;
                }
                else
                    downRow = i;
            }
            else
                total += room[i][j];
        }
    }
}

void spreadDust()
{
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            int cnt = 0;
            int val = room[i][j] / 5;
            if (room[i][j] == 0 || room[i][j] == -1)
                continue;

            int nr, nc;
            for (int k = 0; k < 4; ++k)
            {
                nr = i + dr[k];
                nc = j + dc[k];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C || room[nr][nc] == -1)
                    continue;
                
                add[nr][nc] += val;
                cnt++;
            }
            add[i][j] -= (cnt * val);
        }
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            room[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void airCleaner()
{
    total -= room[upRow - 1][0];
    total -= room[downRow + 1][0];

    for (int i = upRow - 1; i > 0; --i)
        room[i][0] = room[i - 1][0];
    for (int i = 0; i < C - 1; ++i)
        room[0][i] = room[0][i + 1];
    for (int i = 1; i <= upRow; ++i)
        room[i - 1][C - 1] = room[i][C - 1];
    for (int i = C - 1; i > 1; --i)
        room[upRow][i] = room[upRow][i - 1];
    room[upRow][1] = 0;

    for (int i = downRow + 1; i < R - 1; ++i)
        room[i][0] = room[i + 1][0];
    for (int i = 0; i < C - 1; ++i)
        room[R - 1][i] = room[R - 1][i + 1];
    for (int i = R - 1; i >= downRow; --i)
        room[i][C - 1] = room[i - 1][C - 1];
    for (int i = C - 1; i > 1; --i)
        room[downRow][i] = room[downRow][i - 1];
    room[downRow][1] = 0;
}

void solve()
{
    while (T--)
    {
        spreadDust();
        airCleaner();
    }

    cout << total;
}

int main()
{
    input();
    solve();

    return 0;
}