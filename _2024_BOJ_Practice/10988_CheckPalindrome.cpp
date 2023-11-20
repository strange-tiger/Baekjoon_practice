#include <iostream>
using namespace std;

string S;
int length = 0;
int cnt = 0;

int main()
{
	cin >> S;

	length = S.size();
	cnt = length / 2;

	while (cnt--)
	{
		if (S[cnt] != S[length - cnt - 1])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}