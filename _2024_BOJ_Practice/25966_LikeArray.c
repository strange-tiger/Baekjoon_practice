#include <stdio.h>
#define MAX 3000

int N, M, q;
int O, I, J, K;
int i, j, temp;
int arr[MAX][MAX];
int swapIndex[MAX];

void Swap(int a, int b)
{
    temp = swapIndex[a];
    swapIndex[a] = swapIndex[b];
    swapIndex[b] = temp;
}

void Change(int a, int b, int v)
{
    arr[swapIndex[a]][b] = v;
}

int main()
{
    scanf("%d %d %d", &N, &M, &q);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            scanf("%d", &arr[i][j]);
        swapIndex[i] = i;
    }

    while (q--)
    {
        scanf("%d", &O);

        if (O)
        {
            scanf("%d %d", &I, &J);
            Swap(I, J);
        }
        else
        {
            scanf("%d %d %d", &I, &J, &K);
            Change(I, J, K);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            printf("%d ", arr[swapIndex[i]][j]);
        printf("\n");
    }
    return 0;
}