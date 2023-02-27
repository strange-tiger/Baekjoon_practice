#include <iostream>
using namespace std;

int N;
int Min = 1000001;
int house[1000][3];
int painted[1001][3] = { 0 };
void paint()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			painted[i + 1][j] = min(painted[i][(j + 1) % 3], painted[i][(j + 2) % 3]);
			painted[i + 1][j] += house[i][j];
		}
	}

	for (int cost : painted[N])
		if (Min > cost)
			Min = cost;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> house[i][0] >> house[i][1] >> house[i][2];

	paint();

	cout << Min;

	return 0;
}