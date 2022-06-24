#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N, M;
int* findNum;
int main()
{
	scanf("%d %d", &N, &M);

	findNum = new int[M];
	
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &findNum[i]);
	}

	int cursor = 1;
	int lst = 0;
	int rttLeft = 0;
	int rttRight = 0;
	for (int i = 0; i < M; ++i)
	{
		if (cursor == findNum[i])
		{
			lst += 0;
		}
		else if (cursor > findNum[i])
		{
			rttLeft = N - i - cursor + findNum[i];
			rttRight = cursor - findNum[i];

			rttLeft > rttRight ? lst += rttRight : lst += rttLeft;

			cursor = findNum[i];
		}
		else if (cursor < findNum[i])
		{
			rttLeft = findNum[i] - cursor;
			rttRight = cursor + N - i - findNum[i];

			rttLeft > rttRight ? lst += rttRight : lst += rttLeft;

			cursor = findNum[i];
		}

		for (int j = i; j < M; ++j)
		{
			if (findNum[j] > cursor)findNum[j]--;
		}
	}
	printf("%d", lst);

	delete[] findNum;

	return 0;

	// with deque
}