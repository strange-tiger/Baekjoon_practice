#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>


long long N, M, max = 0;
long long tree[1000000];
int main()
{
	scanf("%ld %ld", &N, &M);

	for (long long i = 0; i < N; ++i)
	{
		scanf("%ld", &tree[i]);

		if (max < tree[i])
		{
			max = tree[i];
		}
	}

	long long s = 1;
	long long e = max + 1;
	long long result = 0;
	while (s < e)
	{
		long long m = (s + e) / 2;
		
		long long length = 0;
		for (long long i = 0; i < N; ++i)
		{
			if (tree[i] > m)
				length += tree[i] - m;
		}
	
		if (length >= M)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}
		else
		{
			e = m;
		}
	}

	printf("%ld", result);
}