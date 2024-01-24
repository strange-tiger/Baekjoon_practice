#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N;
int A[1001];
int Li[1001];
int Ld[1001];
int Answer = 0;
int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    for (int i = 0; i < N; ++i)
    {
        Li[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (A[i] > A[j])
            {
                Li[i] = Li[i] > (Li[j] + 1) ? Li[i] : (Li[j] + 1);
            }
        }
    }

    for (int i = N - 1; i >= 0; --i)
    {
        Ld[i] = 1;
        for (int j = N - 1; j > i; --j)
        {
            if (A[i] > A[j])
            {
                Ld[i] = Ld[i] > (Ld[j] + 1) ? Ld[i] : (Ld[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; ++i)
        Answer = Answer < Li[i] + Ld[i] - 1 ? Li[i] + Ld[i] - 1 : Answer;

    printf("%d", Answer);

    return 0;
}