#include <iostream>
using namespace std;

int N;
int Max = -2e9;
int Min = 2e9;
int A[11];
int Operator[4] = { 0 };

int calculate(int i, int result, int num)
{
	switch (i)
	{
	case 0:
		return result += num;
	case 1:
		return result -= num;
	case 2:
		return result *= num;
	case 3:
		return result /= num;
	}
}

void operating(int num, int result)
{
	if (num >= N)
	{
		if (Max < result)
			Max = result;
		if (Min > result)
			Min = result;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (Operator[i])
		{
			--Operator[i];

			operating(num + 1, calculate(i, result, A[num]));

			++Operator[i];
		}
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	for (int i = 0; i < 4; ++i)
		cin >> Operator[i];

	operating(1, A[0]);

	cout << Max << '\n';
	cout << Min << '\n';

	return 0;
}