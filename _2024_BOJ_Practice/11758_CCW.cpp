#include <iostream>
using namespace std;

int outer;
int p1[2], p2[2], p3[2];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> p1[0] >> p1[1];
	cin >> p2[0] >> p2[1];
	cin >> p3[0] >> p3[1];
}

void ccw()
{
	outer = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1];
	outer -= p1[1] * p2[0] + p2[1] * p3[0] + p3[1] * p1[0];
}

void solve()
{
	ccw();

	if (outer > 0)
		cout << 1;
	else if (outer < 0)
		cout << -1;
	else
		cout << 0;
}

int main()
{
	input();
	solve();
	return 0;
}