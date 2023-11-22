#include <iostream>
using namespace std;

string N;
int B = 0;
int result = 0;
int i = 0;
int temp = 0;
int cnt = 0;

int main()
{
	cin >> N >> B;

	for (i = N.size() - 1; i >= 0; --i)
	{
		if (N[i] <= '9')
			temp = (int)N[i] - 48;
		else if (N[i] >= 'A')
			temp = (int)N[i] - 55;
		
		cnt = N.size() - i - 1;

		while (cnt--)
			temp *= B;

		result += temp;
	}

	cout << result;

	return 0;
}