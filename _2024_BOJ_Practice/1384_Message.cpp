#include <iostream>
#include <string>
using namespace std;

int n, i, j, Index, cnt = 0;
char message;
bool isNasty = false;
string name[20];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> n, n != 0)
    {
        ++cnt;
        bool papers[20][20] = { false };
        isNasty = false;

        for (i = 0; i < n; ++i)
        {
            cin >> name[i];
            for (j = 1; j < n; ++j)
            {
                cin >> message;

                if (message == 'P')
                {
                    papers[i][j] = false;
                }
                else
                {
                    papers[i][j] = true;
                    isNasty = true;
                }
            }
        }

        cout << "Group " << cnt << '\n';
        if (isNasty)
        {
            for (i = 0; i < n; ++i)
            {
                for (j = 1; j < n; ++j)
                {
                    if (papers[i][j])
                    {
                        Index = (i - j) < 0 ? n + i - j : i - j;
                        cout << name[Index] << " was nasty about " << name[i] << '\n';
                    }
                }
            }
        }
        else
        {
            cout << "Nobody was nasty" << '\n';
        }
        cout << '\n';
    }

    return 0;
}