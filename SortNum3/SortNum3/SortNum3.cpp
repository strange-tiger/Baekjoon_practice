#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int cnt[10001] = { 0 };

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);

		cnt[temp]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}