#include <iostream>
#include <string>
using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	string str[50];

	for (int i = 0; i < N; ++i)
	{
		cin >> str[i];
	}

	string result;
	
	result = str[0];
	for (int i = 1; i < N; ++i)
	{
		int length = str[i].length();
		for (int j = 0; j < length; ++j)
		{
			if (result[j] != str[i][j])
			{
				result[j] = '?';
			}
		}
	}

	cout << result << '\n';

	return 0;
}