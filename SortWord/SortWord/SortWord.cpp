#include <iostream>
#include <algorithm>
using namespace std;

bool comp(string& left, string& right)
{
	if (left.size() < right.size())
	{
		return true;
	}
	else if (left.size() == right.size())
	{
		return left < right;
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	cin >> N;

	string* str = new string[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> str[i];
	}

	sort(str, str + N, comp);

	for (int i = 0; i < N; ++i)
	{
		if (str[i] != str[i + 1])
			cout << str[i] << '\n';
	}

	delete[] str;
	return 0;
}
