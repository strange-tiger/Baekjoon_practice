#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, answer = 0;
string A, B;
map<string, bool> rainbowDance;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	rainbowDance["ChongChong"] = true;
	while (N--)
	{
		cin >> A >> B;
		
		if (rainbowDance[A])
		{
			rainbowDance[B] = true;
		}
		else if (rainbowDance[B])
		{
			rainbowDance[A] = true;
		}
		else
		{
			rainbowDance[A] = false;
			rainbowDance[B] = false;
		}
	}

	for (pair<string, bool> person : rainbowDance)
		if (person.second)
			++answer;

	cout << answer;

	return 0;
}