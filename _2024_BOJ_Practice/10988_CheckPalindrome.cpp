#include <iostream>
using namespace std;

string S;
int length = 0;
int j = 0;

int main()
{
	cin >> S;

	length = S.size();
	j = length / 2;

	while (j--)
	{
		if (S[j] != S[length - j - 1])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}