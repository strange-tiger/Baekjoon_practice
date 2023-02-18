#include <iostream>
using namespace std;

int num;
int total;
bool area[100][100] = { false };
int main(void)
{
	cin >> num;

	int i, j, k;

	int** papers = new int*[num];
	for (i = 0; i < num; ++i)
	{
		papers[i] = new int[2];
	}

	for (i = 0; i < num; ++i)
	{
		cin >> papers[i][0];
		cin >> papers[i][1];
	}

	int x, y;
	for (i = 0; i < num; ++i)
	{
		x = papers[i][0], y = papers[i][1];
		for (j = x; j < x + 10; ++j)
		{
			for (k = y; k < y + 10; ++k)
			{
				if (!area[j][k])
				{
					area[j][k] = true;
					++total;
				}
			}
		}
	}

	cout << total;

	for (i = 0; i < num; ++i)
	{
		delete[] papers[i];
	}

	delete[] papers;

	return 0;
}