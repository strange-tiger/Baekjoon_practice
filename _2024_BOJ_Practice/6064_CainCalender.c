#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int T, M, N, x, y, ans;
int main()
{
	scanf("%d", &T);

	int i = 0;
	while (T--)
	{
		scanf("%d %d %d %d", &M, &N, &x, &y);

		if (x == y)
		{
			printf("%d\n", x);
			continue;
		}

		for (i = 1; M * i % N != 0; ++i)
		{
			ans = M * i + x;

			if (ans % N == y % N)
			{
				printf("%d\n", ans);
				break;
			}
		}

		if (M * i % N == 0)
		{
			if (M == x && N == y)
			{
				printf("%d\n", M * i);
				continue;
			}
			else
			{
				printf("-1\n");
			}
		}
	}

	return 0;
}