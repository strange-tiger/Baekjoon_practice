#include <iostream>
using namespace std;

int T, N, i;
int cnt = 0;
int perm[1001] = { 0 };
bool isVisited[1001] = { false };

int getCycle(int v)
{
    if (isVisited[v])
    {
        ++cnt;

        while (isVisited[v])
            ++v;

        if (v <= N)
            getCycle(v);
    }
    else
    {
        isVisited[v] = true;
        getCycle(perm[v]);
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;
        for (i = 1; i <= N; ++i)
            cin >> perm[i];

        cnt = 0;
        for (i = 1; i <= N; ++i)
            isVisited[i] = false;

        cout << getCycle(1) << '\n';
    }
    return 0;
}