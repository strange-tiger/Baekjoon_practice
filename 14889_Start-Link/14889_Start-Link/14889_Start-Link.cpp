#include <iostream>
#include <math.h>
using namespace std;

int N;
int Min = 1001;
int S[20][20];
bool team[20] = { false };
int calculate()
{
	int sumOne = 0;
	int sumTwo = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (team[i] && team[j])
				sumOne += S[i][j];
			else if (!(team[i] || team[j]))
				sumTwo += S[i][j];
		}
	}

	return abs(sumOne - sumTwo);
}

void split(int num)
{
	if (num >= N / 2)
	{
		int difference = calculate();
		if (Min > difference)
			Min = difference;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (team[i])
			continue;

		team[i] = true;

		split(num + 1);

		team[i] = false;
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> S[i][j];

	split(0);

	cout << Min;

	return 0;
}