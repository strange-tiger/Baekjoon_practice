#include <iostream>
#include <cstring>
#define star '*'
using namespace std;

int N, i, j;
char arr[397][397];

void draw(int len, int row, int col)
{
    for (i = 0; i < len; ++i)
    {
        arr[row][col + i] = star;
        arr[row + len - 1][col + i] = star;
    }

    for (i = 1; i < len - 1; ++i)
    {
        arr[row + i][col] = star;
        arr[row + i][col + len - 1] = star; 
    }
}

void square(int n, int row, int col)
{
    int len = 4 * n - 3;

    draw(len, row, col);

    if (n == 1)
        return;

    square(n - 1, row + 2, col + 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    memset(arr, ' ', sizeof(arr));

    square(N, 0, 0); 

    for (i = 0; i < 4 * N - 3; ++i)
    {
        for (j = 0; j < 4 * N - 3; ++j)
            cout << arr[i][j];

        cout << '\n';
    }

    return 0;
}