#include <iostream>
#include <string>
using namespace std;

int q, l, r;
int i, j, alpha;
char a;
string S;
int counts[27][200001] = { 0 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    

    cin >> S >> q;

    counts[S[0] - 'a'][0] = 1;

    for (i = 1; i < S.size(); ++i)
    {
        for (j = 0; j < 27; ++j)
            counts[j][i] = counts[j][i - 1];

        ++counts[S[i] - 'a'][i];
    }

    while(q--)
    {
        cin >> a >> l >> r;

        alpha = a - 'a';

        if (l == 0)
            cout << counts[alpha][r] << '\n';
        else
            cout << counts[alpha][r] - counts[alpha][l - 1] << '\n';
    }

    return 0;
}