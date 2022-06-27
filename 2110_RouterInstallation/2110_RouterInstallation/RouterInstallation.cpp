#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using L = long long;

L N, C, max = 0;
L pos[200000];
L dis[199999];
int main()
{
	scanf("%ld %ld", &N, &C);

	for (L i = 0; i < N; ++i)
	{
		scanf("%ld", &pos[i]);
	}

	std::sort(pos, pos + N);

	for (L i = 0; i < N - 1; ++i)
	{
		dis[i] = pos[i + 1] - pos[i];

		if (max < dis[i])
		{
			max = dis[i];
		}
	}

	L s = 1;
	L e = pos[N - 1] - pos[0] + 1;
	L result = e - 1;
	while (s < e)
	{
		L m = (s + e) / 2;
		
		L distance = 0;
		for (L i = 0; i < C; ++i)
		{
			distance += dis[i];
		}

		if (result > distance)
		{
			result = distance;
		}
	}

	return 0;
}