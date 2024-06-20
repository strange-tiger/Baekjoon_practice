#include <iostream>
#include <string>
using namespace std;

int x, y;
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string week[7] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y;
}

void solve()
{
	int day = 0;

	for (int i = 0; i < x; ++i)
		day += month[i];
	day += y;

	cout << week[day % 7];
}

int main()
{
	input();
	solve();
	return 0;
}