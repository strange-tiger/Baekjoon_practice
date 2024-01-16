#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define MAX 1000000

int T, N, cnt = 0;
int prime[MAX + 1];
int main()
{
    for (int i = 2; i <= MAX; ++i)
        prime[i] = i;

    for (int i = 2; i * i <= MAX; ++i)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j <= MAX; j += i)
            prime[j] = 0;
    }

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);
		cnt = 0;

        for (int i = 2; i < N; i++)
        {
            if (prime[N - i] && prime[i])
                cnt++;
            if (N - i == i)
                cnt++;
        }
        printf("%d\n", cnt / 2);
	}

    return 0;
}