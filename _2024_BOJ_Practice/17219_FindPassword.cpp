#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;
string site, password;
unordered_map<string, string> notepad;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	while (N--)
	{
		cin >> site >> password;
		notepad.insert({ site, password });
	}

	while (M--)
	{
		cin >> site;
		cout << notepad[site] << '\n';
	}

	return 0;
}