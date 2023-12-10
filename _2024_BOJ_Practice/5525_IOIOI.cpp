#include <iostream>
#include <string>
using namespace std;

int N, M;
int result = 0;
int i, j = 0;
string S;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> S;

    for (i = 0; i < M - 2; ++i)
    {
        if (S[i] == 'I')
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                ++j;
                if (j == N)
                {
                    --j;
                    ++result;
                }
                i += 2;
            }
            j = 0;
        }
    }
    cout << result;

    return 0;
}