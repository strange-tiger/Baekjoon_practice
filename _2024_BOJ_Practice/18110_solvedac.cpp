#include <iostream>
using namespace std;

int N = 0;
int cut = 0;
int Max = 0, Min = 31;
int result = 0;
int difficultySum = 0;

int main()
{
	cin >> N;

	if (N)
	{
		cout << result;
		return 0;
	}

	float bcut = N * 0.15f;
	cut = (int)bcut;

	if (bcut - cut >= 0.5f)
		++cut;


}