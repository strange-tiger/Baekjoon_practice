#include <iostream>
using namespace std;

int N;
int Max = 0;
int meeting[100000][2];
void insertionSort()
{
	int tmp[2];
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j > 0 && meeting[j][1] < meeting[j - 1][1]; --j)
		{
			tmp[0] = meeting[j][0];
			tmp[1] = meeting[j][1];
			meeting[j][0] = meeting[j - 1][0];
			meeting[j][1] = meeting[j - 1][1];
			meeting[j - 1][0] = tmp[0];
			meeting[j - 1][1] = tmp[1];
		}
	}
}

void schedule(int index, int cnt)
{
	for (int i = index + 1; i < N; ++i)
		if (meeting[index][1] <= meeting[i][0])
			schedule(i, cnt + 1);

	if (Max < cnt)
		Max = cnt;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> meeting[i][0] >> meeting[i][1];

	insertionSort();

	schedule(0, 1);

	cout << Max;

	return 0;
}