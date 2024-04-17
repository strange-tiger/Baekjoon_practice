#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, tmp, Max;
long long result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> N;
        vector<int> v;

        for (int i = 0; i < N; ++i)
        {
            cin >> tmp;
            v.push_back(tmp);
        }

        result = 0;
        Max = -1;

        for (int i = N - 1; i >= 0; --i)
        {
            Max = max(Max, v[i]);
            result += Max - v[i];
        }

        cout << result << '\n';
    }
}