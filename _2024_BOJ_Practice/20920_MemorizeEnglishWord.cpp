#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
string word;
vector<string> voca;
map<string, int> freq;

bool compare(string a, string b)
{
	if (a.size() == b.size() && freq[a] == freq[b])
		return a < b;
	else if (freq[a] == freq[b])
		return a.size() > b.size();
	else
		return freq[a] > freq[b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (N--)
	{
		cin >> word;
		
		if (word.size() < M)
			continue;
		
		if (freq.find(word) == freq.end())
		{
			freq[word] = 0;
			voca.push_back(word);
		}

		++freq[word];
	}
	sort(voca.begin(), voca.end(), compare);

	for (int i = 0; i < voca.size(); ++i)
		cout << voca[i] << '\n';

	return 0;
}