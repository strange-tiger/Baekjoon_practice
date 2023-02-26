#include <iostream>
using namespace std;

int N;
int f[1000000];
int fibonacci(int n)
{
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < n; ++i)
	{
		f[i] = (f[i - 1] + f[i - 2]) % 15746;
	}

	return f[n - 1];
}


int main(void)
{
	cin >> N;

	cout << fibonacci(N);

	return 0;
}