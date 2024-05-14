#include <iostream>
#include <vector>
#include <utility>
#include <set>
#define pos pair<int, int>
#define X first
#define Y second
#define X1 X.X
#define Y1 X.Y
#define X2 Y.X
#define Y2 Y.Y
using namespace std;

int N;
int parent[1001];
pair<pos, pos> tmp;
vector<pair<pos, pos>> rect;
set<int> eulerianTrail;

int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int a, int b)
{
	int x = findParent(a);
	int y = findParent(b);

	if (x < y)
		parent[y] = x;
	else if (x > y)
		parent[x] = y;
}

bool overlap(int i, int j)
{
	pair<pos, pos> a = rect[i];
	pair<pos, pos> b = rect[j];

	if (a.X1 > b.X1 && a.Y1 > b.Y1 && a.X2 < b.X2 && a.Y2 < b.Y2)
		return false;
	else if (a.X1 < b.X1 && a.Y1 < b.Y1 && a.X2 > b.X2 && a.Y2 > b.Y2)
		return false;
	else if (a.X1 > b.X2 || a.Y1 > b.Y2 || a.X2 < b.X1 || a.Y2 < b.Y1)
		return false;
	return true;
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	tmp.X1 = 0;
	tmp.Y1 = 0;
	tmp.X2 = 0;
	tmp.Y2 = 0;
	rect.push_back(tmp);
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp.X1 >> tmp.Y1 >> tmp.X2 >> tmp.Y2;
		rect.push_back(tmp);
	}

	for (int i = 0; i <= N; ++i)
		parent[i] = i;
}

void solve()
{
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			if (overlap(i, j))
				merge(i, j);

	for (int i = 0; i <= N; ++i)
		eulerianTrail.insert(findParent(parent[i]));

	cout << eulerianTrail.size() - 1;
}

int main()
{
	input();
	solve();
	return 0;
}