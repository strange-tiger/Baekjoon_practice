#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int i, j;
int cnt = 0;
queue<pair<int, int>> hint;
string puzzle[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (i = 0; i < N; ++i)
        cin >> puzzle[i];

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < M; ++j)
        {
            if (puzzle[i][j] == '.')
            {
                if ((i == 0 || puzzle[i - 1][j] == '#') && (i + 2 < N && puzzle[i + 1][j] == '.' && puzzle[i + 2][j] == '.'))
                {
                    ++cnt;
                    hint.push({ i + 1, j + 1 });
                }
                else if ((j == 0 || puzzle[i][j - 1] == '#') && (j + 2 < M && puzzle[i][j + 1] == '.' && puzzle[i][j + 2] == '.'))
                {
                    ++cnt;
                    hint.push({ i + 1, j + 1 });
                }
            }
        }
    }

    cout << cnt << '\n';
    while (!hint.empty())
    {
        cout << hint.front().first << ' ' << hint.front().second << '\n';
        hint.pop();
    }

    return 0;
}