#include <iostream>
#include <set>
using namespace std;

string S, key;
int SLen;
set <string> differGroup;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	SLen = S.size();

	for (int i = 0; i < SLen; ++i)
	{
		key.clear();
		for (int j = i; j < SLen; ++j)
		{
			key += S[j];
			differGroup.insert(key);
		}
	}

	cout << differGroup.size();

	return 0;
}