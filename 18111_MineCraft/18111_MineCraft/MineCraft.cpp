#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define _INF 64000000

int map[500][500] = { 0 };

int N, M, B, time = 0;
int main()
{
	scanf("%d %d %d", &N, &M, &B);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}

	int leastTime = _INF;
	int maxHeight = 0;
	for (int h = 0; h <= 256; ++h)
	{
		int bld = 0;
		int dig = 0;
		for (int r = 0; r < N; ++r)
		{
			for (int c = 0; c < M; ++c)
			{
				int irreg = map[r][c] - h;

				if (irreg > 0)
					dig += irreg;
				else if (irreg < 0)
					bld -= irreg;
			}
		}

		if (dig + B >= bld)
		{
			int time = 2 * dig + bld;
			if (leastTime >= time)
			{
				leastTime = time;
				maxHeight = h;
			}
		}
	}

	printf("%d %d\n", leastTime, maxHeight);

	return 0;
}

#pragma region 최서연_코드
/*
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int n, m, b;
int counts[257] = { 0 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> b;

	int temp;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			++counts[temp];
		}
	}

	int minTime = 99999999;
	int maxHeight = 0;
	for (int i = 0; i <= 256; ++i)
	{
		int currentTime = 0;

		int subblock = 0;
		for (int j = i + 1; j <= 256; ++j)
		{
			subblock += counts[j] * (j - i);
		}

		int addblock = 0;
		for (int j = 0; j < i; ++j)
		{
			addblock += counts[j] * (i - j);
		}

		if (addblock > b + subblock)
			continue;

		currentTime += addblock + subblock * 2;

		if (minTime > currentTime)
		{
			minTime = currentTime;
			maxHeight = i;
		}
		else if (minTime == currentTime && maxHeight < i)
		{
			maxHeight = i;
		}
	}

	cout << minTime << " " << maxHeight << "\n";

	return 0;
}
*/
#pragma endregion