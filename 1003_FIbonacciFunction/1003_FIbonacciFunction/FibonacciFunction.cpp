#include <iostream>
using namespace std;

int cnt[41][2] = {0};

int T, N;
int main()
{
    cin >> T;

    cnt[0][0] = 1;
    cnt[0][1] = 0;
    cnt[1][0] = 0;
    cnt[1][1] = 1;

    for (int i = 2; i <= 40; ++i)
    {
        cnt[i][0] = cnt[i - 1][0] + cnt[i - 2][0];
        cnt[i][1] = cnt[i - 1][1] + cnt[i - 2][1];
    }

    while (T--)
    {
        cin >> N;
                
        cout << cnt[N][0] << " " << cnt[N][1] << "\n";
    }
}