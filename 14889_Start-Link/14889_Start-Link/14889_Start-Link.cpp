#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int N;
int Min = 1001;
int S[20][20];
bool team[20] = { false };
vector<int> teamOne;
vector<int> teamTwo;

int sumOne;
int sumTwo;
int calculate()
{
	sumOne = 0;
	sumTwo = 0;

	teamOne.clear();
	teamTwo.clear();

	for (int i = 0; i < N; ++i)
	{
		if (team[i])
			teamOne.push_back(i);
		else
			teamTwo.push_back(i);
	}

	for (int i : teamOne)
	{
		for (int j : teamOne)
		{
			sumOne += S[i][j];
		}
	}

	for (int i : teamTwo)
	{
		for (int j : teamTwo)
		{
			sumTwo += S[i][j];
		}
	}

	return abs(sumOne - sumTwo);
}

void split(int num, int index)
{
	if (num >= N / 2)
	{
		int difference = calculate();
		if (Min > difference)
			Min = difference;
		return;
	}

	for (int i = index; i < N; ++i)
	{
		team[i] = true;

		split(num + 1, i + 1);

		team[i] = false;
	}
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &S[i][j]);

	split(0, 0);

	printf("%d", Min);

	return 0;
}