#include <iostream>
using namespace std;

int N;
int Min = 1000001;
int house[1000][3];
int painted[1000][3];
int paint(int num, int cost, int prev)
{
	if (num == N)
		return cost;

	int now;
	for (int i = 0; i < 3; ++i)
	{
		if (prev == i)
			continue;

		now = paint(num + 1, cost + house[num][i], i);
		if (Min > now)
			Min = now;
	}

	return Min;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> house[i][0] >> house[i][1] >> house[i][2];

	paint(0, 0, 3);

	cout << Min;

	return 0;
}