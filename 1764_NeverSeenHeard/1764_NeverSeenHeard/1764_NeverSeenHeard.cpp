#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N, M, i;
string name;
map <string, bool> neverSeen;
vector<string> neverSeenHeard;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (i = 0; i < N; ++i)
	{
		cin >> name;
		neverSeen[name] = true;
	}

	for (i = 0; i < M; ++i)
	{
		cin >> name;

		if (neverSeen[name])
			neverSeenHeard.push_back(name);
	}
	sort(neverSeenHeard.begin(), neverSeenHeard.end());

	cout << neverSeenHeard.size() << '\n';
	for (string str : neverSeenHeard)
		cout << str << '\n';

	return 0;
}