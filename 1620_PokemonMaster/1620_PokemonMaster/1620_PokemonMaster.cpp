#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string input, index;
map<string, bool> dictExist;
map<string, string> dictIndex;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> input;
		index = to_string(i);

		dictExist[input] = true;
		dictExist[index] = true;

		dictIndex[input] = index;
		dictIndex[index] = input;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> input;

		if (dictExist[input])
			cout << dictIndex[input] << '\n';
	}

	return 0;
}