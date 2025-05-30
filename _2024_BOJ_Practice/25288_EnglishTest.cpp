// 25288_EnglishTest.cpp
#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int N;
string str;
int main()
{
	fastio;
	cin >> N;
	cin >> str;

	for (int i = 1; i <= N; ++i)
	{
		cout << str;
	}
	return 0;
}