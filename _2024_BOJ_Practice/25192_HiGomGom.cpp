#include <iostream>
#include <unordered_map>
#include <string>
#define ENTER "ENTER"
using namespace std;

int N, answer = 0;
string chat;
unordered_map<string, bool> member;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--)
	{
		cin >> chat;

		if (chat == ENTER)
		{
			member.clear();
		}
		else if (!member[chat])
		{
			member[chat] = true;
			++answer;
		}
	}

	cout << answer;

	return 0;
}