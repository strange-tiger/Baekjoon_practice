#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int A, B, T;
int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; ++i)
	{
		scanf("%d %d", &A, &B);
		
		int less, more;

		if (A > B)
		{
			less = B;
			more = A;
		}
		else
		{
			less = A;
			more = B;
		}

		while (1)
		{
			if (!(more % less))
			{
				break;
			}
			more = more % less;

			int temp;
			temp = more;
			more = less;
			less = temp;
		}

		printf("%d\n", A * B / less);
	}

	return 0;
}