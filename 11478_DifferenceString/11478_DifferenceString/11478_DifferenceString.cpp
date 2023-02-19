#include <iostream>
#include <map>
using namespace std;

string S, key;
int SLen;
map <string, bool> differGroup;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	SLen = S.size();

	for (int i = SLen; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			key.clear();

			for (int k = 0; k < SLen - i + 1; ++k)
				key.push_back(S[j + k]);

			differGroup[key] = true;
		}
	}

	cout << differGroup.size();

	return 0;
}