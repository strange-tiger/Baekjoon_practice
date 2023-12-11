#include <iostream>
#include <string>
using namespace std;

int N, M;
int channel = 100;
int cnt1, cnt2;
bool brokenButton[10] = { false };

bool setButton(int num)
{
    string s = to_string(num);
    
    for (int i = 0; i < s.length(); ++i)
        if (brokenButton[s[i] - '0'] == 1)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int temp;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        brokenButton[temp] = true;
    }

    cnt1 = abs(N - channel);

    for (int i = 0; i < 1000001; ++i)
    {
        if (setButton(i) == true)
        {
            cnt2 = abs(N - i) + to_string(i).length();
            cnt1 = min(cnt1, cnt2);
        }
    }
    cout << cnt1;

    return 0;
}