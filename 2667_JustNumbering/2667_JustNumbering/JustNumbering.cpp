#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int house[625] = { 0 };
bool isVisited[625] = { false };
int N;
void dfs(int ver, int& cnt)
{
	isVisited[ver] = true;
	++cnt;

	int up = ver - N;
	int right = ver + 1;
	int left = ver - 1;
	int down = ver + N;

	if (up >= 0)
	{
		if (!isVisited[up])
		{
			if (1 == house[up])
				dfs(up, cnt);
		}
	}

	if (right % N != 0)
	{
		if (!isVisited[right])
		{
			if (1 == house[right])
				dfs(right, cnt);
		}
	}

	if (down < N * N)
	{
		if (!isVisited[down])
		{
			if (1 == house[down])
				dfs(down, cnt);
		}
	}

	if (left % N != N - 1)
	{
		if (!isVisited[left])
		{
			if (1 == house[left])
				dfs(left, cnt);
		}
	}
}

int main()
{
	scanf("%d", &N);

	int cnt = 0;
	while (cnt != N * N)
	{
		int temp = getchar() - '0';
		if (1 == temp || 0 == temp)
		{
			house[cnt] = temp;
			++cnt;
		}
	}

	int complexNum = 0;
	int houseNum[313] = { 0 };
	for (int i = 0; i < N * N; ++i)
	{
		int& num = houseNum[complexNum];

		if (1 == house[i])
		{
			if (!isVisited[i])
			{
				++complexNum;
				dfs(i, num);
			}
		}
	}

	printf("%d\n", complexNum);

	std::sort(houseNum, houseNum + complexNum);
	for (int i = 0; i < complexNum; ++i)
	{
		printf("%d\n", houseNum[i]);
	}

	return 0;
}