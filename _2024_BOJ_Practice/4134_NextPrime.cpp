#include <iostream>
using namespace std;

int T;
long long int n;

long long int findPrime(long long int num)
{
	if (num <= 1)
		return findPrime(++num);
	for (long long int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return findPrime(++num);
	return num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> n;

		n = findPrime(n);
		
		cout << n << '\n';
	}

	return 0;
}