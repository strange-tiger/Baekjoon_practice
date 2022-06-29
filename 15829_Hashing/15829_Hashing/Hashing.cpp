#include <iostream>
#include <string>
using namespace std;

int L;
string str;
int main()
{
	cin >> L;
	cin >> str;

	long long sum = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		long long a = (str[i] - 'a' + 1);
		for (int j = 0; j < i; ++j)
		{
			a *= 31;
			a %= 1234567891;
		}

		sum += a;
		sum %= 1234567891;
	}

	int hash;
	hash = sum % 1234567891;

	cout << hash;

	return 0;
}