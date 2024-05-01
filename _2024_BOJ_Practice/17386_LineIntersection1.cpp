#include <iostream>
#define L long long
using namespace std;

L point[4][2];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; ++i)
		cin >> point[i][0] >> point[i][1];
}

int ccw(L a[2], L b[2], L c[2])
{
	L tmp = a[0] * b[1] + b[0] * c[1] + c[0] * a[1];
	tmp -= a[0] * c[1] + b[0] * a[1] + c[0] * b[1];

	if (tmp > 0)
		return 1;
	else if (tmp == 0)
		return 0;
	else
		return -1;
}

void solve()
{
	int line1 = ccw(point[0], point[1], point[2]) * ccw(point[0], point[1], point[3]);
	int line2 = ccw(point[0], point[2], point[3]) * ccw(point[1], point[2], point[3]);

	if (line1 < 0 && line2 < 0)
		cout << 1;
	else
		cout << 0;
}

int main()
{
	input();
	solve();
	return 0;
}