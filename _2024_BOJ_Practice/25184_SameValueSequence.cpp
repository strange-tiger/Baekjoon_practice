// 25184_SameValueSequence
#include <iostream>
using namespace std;

int N;
int main()
{
    cin >> N;

    for (int i = N / 2; i > 0; --i)
    {
        cout << i << " " << i + N / 2 << " ";
    }
    if (N % 2 == 1)
    {
        cout << N;
    }
    return 0;
}