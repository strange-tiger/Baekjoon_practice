#include<iostream>
#include<map>
#include<string>
#define MAX 200001
using namespace std;

int T, cnt, num;
int parent[MAX];
int friends[MAX];
int fCode[2];
string fName[2];
map<string, int> name;

int Find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
	{
		parent[b] = a;
		friends[a] += friends[b];
	}
}

void input()
{
	name.clear();
	cnt = 0;

	for (int i = 0; i < MAX; ++i)
	{
		parent[i] = i;
		friends[i] = 1;
	}

	cin >> num;
}

void solve()
{
	for (int i = 0; i < num; ++i)
	{
		cin >> fName[0] >> fName[1];

		for (int j = 0; j < 2; ++j)
		{
			if (name.find(fName[j]) == name.end())
			{
				name[fName[j]] = ++cnt;
				fCode[j] = cnt;
			}
			else
				fCode[j] = name[fName[j]];
		}

		Union(fCode[0], fCode[1]);
		cout << friends[Find(fCode[0])] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		input();
		solve();
	}

	return 0;
}