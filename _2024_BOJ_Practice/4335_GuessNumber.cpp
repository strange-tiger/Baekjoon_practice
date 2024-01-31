#include <iostream>
#include <string>
#define MAX 11
#define MIN 0
using namespace std;

int num, i;
bool isHonest = true;
string stan;
int tooHigh = MAX;
int tooLow = MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> num, num != 0)
    {
        cin >> stan >> stan;

        if (stan == "high")
        {
            tooHigh = min(num, tooHigh);

            if (num <= tooLow)
                isHonest = false;
        }
        else if (stan == "low")
        {
            tooLow = max(num, tooLow);

            if (num >= tooHigh)
                isHonest = false;
        }
        else
        {
            if (num <= tooLow)
                isHonest = false;
            else if (num >= tooHigh)
                isHonest = false;

            if (isHonest)
                cout << "Stan may be honest" << '\n';
            else
                cout << "Stan is dishonest" << '\n';
            isHonest = true;
            tooHigh = MAX;
            tooLow = MIN;
        }
    }

    return 0;
}