#include <iostream>
#include <string>
#define ll long long
#define MAX 641
using namespace std;

ll N, i, j, k, num, cnt = 0;
string str;

bool ableNum(string s)
{
	num = 0;

	for (char c : s)
	{
		num *= 10;
		num += c - '0';
	}

	return num <= 641;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> str;

	for (i = 0; i < N; ++i)
	{
		j = i + 3; k = i + 2;
		if ((j == N || (j < N && str[j] != '0'))
			&& ableNum(str.substr(i, 3)))
			i += 2;
		else if ((k == N || (k < N && str[k] != '0'))
			&& ableNum(str.substr(i, 2)))
			i += 1;
		++cnt;
	}

	cout << cnt;

	return 0;
}