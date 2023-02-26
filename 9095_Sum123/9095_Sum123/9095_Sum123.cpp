#include <iostream>
using namespace std;

int T, n;
int result[10] = { 0 };
int sum(int num)
{
	if (result[num - 1] || num < 4)
		return result[num - 1];
	
	for (int i = 3; i > 0; --i)
		result[num - 1] += sum(num - i);

	return result[num - 1];
}

int main(void)
{
	cin >> T;

	result[0] = 1; // n == 1, sum(n) = 1
	result[1] = 2; // n == 2, sum(n) = 2
	result[2] = 4; // n == 3, sum(n) = 4

	while (T--)
	{
		cin >> n;

		cout << sum(n) << '\n';
	}
	return 0;
}