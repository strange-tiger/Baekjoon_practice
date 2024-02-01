#include <iostream>
#include <string>
using namespace std;

int M, n;
int i, j;
int dir = 0;
int loc[2] = { 0, 0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool isAvailable = true;
int para;
string order;

void Turn(int d)
{
    if (d)
    {
        if (dir == 3)
            dir = -1;
        ++dir;
    }
    else
    {
        if (dir == 0)
            dir = 4;
        --dir;
    }
}

bool Check()
{
    if (loc[0] > M || loc[0] < 0 || loc[1] > M || loc[1] < 0)
        isAvailable = false;
    return isAvailable;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> n;

    while (n--)
    {
        cin >> order >> para;

        if (order == "MOVE")
        {
            loc[0] += para * dx[dir];
            loc[1] += para * dy[dir];
        }
        else if (order == "TURN")
            Turn(para);

        if (!Check())
            break;
    }

    if (isAvailable)
        cout << loc[0] << ' ' << loc[1] << '\n';
    else
        cout << -1 << '\n';
    return 0;
}