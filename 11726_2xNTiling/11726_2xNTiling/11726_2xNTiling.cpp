#include <iostream>
using namespace std;

int n;
int result[1000] = { 0 };
int fibonacci(int num)
{
	if (result[num - 1] || num < 3)
		return result[num - 1];

	result[num - 1] = fibonacci(num - 2) + fibonacci(num - 1);

	result[num - 1] %= 10007;

	return result[num - 1];
}

int main(void)
{
	cin >> n;

	result[0] = 1; // n == 1, fibonacci(n) = 1
	result[1] = 2; // n == 2, fibonacci(n) = 2

	cout << fibonacci(n);

	return 0;
}