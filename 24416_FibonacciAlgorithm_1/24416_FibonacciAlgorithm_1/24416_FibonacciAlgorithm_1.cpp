#include <iostream>
using namespace std;

int n;
int cntRe = 0;
int cntDp = 0;
int f[41];
int fib(int num)
{
	if (num == 1 || num == 2)
	{
		++cntRe;
		return 1;
	}

	return fib(num - 2) + fib(num - 1);
}

int fibonacci()
{
	f[1] = f[2] = 1;

	for (int i = 3; i <= n; ++i)
	{
		++cntDp;
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}


int main(void)
{
	cin >> n;

	fib(n);

	fibonacci();

	cout << cntRe << ' ' << cntDp;

	return 0;
}