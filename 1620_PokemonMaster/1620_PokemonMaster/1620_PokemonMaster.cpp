#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string input;
map<string, int> dictName;
map<int, string> dictIndex;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> input;

		dictName[input] = i;
		dictIndex[i] = input;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> input;
		
		if (isdigit(input[0]))
			cout << dictIndex[stoi(input)] << '\n';
		else
			cout << dictName[input] << '\n';
	}

	return 0;
}