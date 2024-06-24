#include <iostream>
#include <algorithm>
using namespace std;

int N, MAX = 0;
char board[51][51];

void cntCandy()
{
    for (int i = 0; i < N; ++i)
    {
        int count = 1;
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == board[i][j + 1])
                ++count;
            else
            {
                if (count > MAX)
                    MAX = count;
                count = 1;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int count = 1;
        for (int j = 0; j < N; ++j)
        {
            if (board[j][i] == board[j + 1][i])
                ++count;
            else
            {
                if (count > MAX)
                    MAX = count;
                count = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            swap(board[i][j], board[i][j + 1]);
            cntCandy();
            swap(board[i][j], board[i][j + 1]);

            swap(board[j][i], board[j + 1][i]);
            cntCandy();
            swap(board[j][i], board[j + 1][i]);
        }
    }

    cout << MAX;
    return 0;
}