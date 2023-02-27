#include <iostream>
using namespace std;

int n, Max = -1001;
int now = 0;
int main(void)
{
	cin >> n;

	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		now += tmp;

		if (Max < now)
			Max = now;

		if (now < 0)
			now = 0;
	}

	cout << Max;

	return 0;
}