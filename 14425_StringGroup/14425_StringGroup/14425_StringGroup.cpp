#include <iostream>
#include <map>
using namespace std;

int N, M, result = 0;
string str;
map<string, bool> hashtable;
int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		hashtable[str] = true;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> str;
		if (hashtable[str]) ++result;
	}

	cout << result;

	return 0;
}