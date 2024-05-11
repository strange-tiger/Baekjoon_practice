#include <iostream>
#include <algorithm>
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

bool isLined(L a[2], L b[2], L c[2])
{
	if (a[0] < b[0])
		return b[0] < c[0];
	else if (a[0] > b[0])
		return b[0] > c[0];

	if (a[1] < b[1])
		return b[1] < c[1];
	else if (a[1] > b[1])
		return b[1] > c[1];
}

bool samePos(L a[2], L b[2])
{
	return a[0] == b[0] && a[1] == b[1];
}

bool comparePos(L a[2], L b[2])
{
	return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

void getIntersection(L a[2], L b[2], L c[2], L d[2])
{
	if (comparePos(b, a))
		swap(a, b);
	if (comparePos(d, c))
		swap(c, d);
	
	double base = (a[0] - b[0]) * (c[1] - d[1]) - (a[1] - b[1]) * (c[0] - d[0]);
	
	if (base == 0)
	{
		if (samePos(b, c) && comparePos(a, c))
			cout << b[0] << ' ' << b[1];
		else if (samePos(a, d) && comparePos(c, a))
			cout << a[0] << ' ' << a[1];
	}
	else
	{
		double AB = a[0] * b[1] - a[1] * b[0];
		double CD = c[0] * d[1] - c[1] * d[0];
		double x = (AB * (c[0] - d[0]) - CD * (a[0] - b[0])) / base;
		double y = (AB * (c[1] - d[1]) - CD * (a[1] - b[1])) / base;

		cout << fixed;
		cout.precision(9);
		cout << x << " " << y;
	}
}

void solve()
{
	int line1 = ccw(point[0], point[1], point[2]) * ccw(point[0], point[1], point[3]);
	int line2 = ccw(point[0], point[2], point[3]) * ccw(point[1], point[2], point[3]);

	if (line1 == 0 && line2 == 0)
	{
		if ((isLined(point[0], point[1], point[2]) && isLined(point[0], point[1], point[3]))
			|| (isLined(point[1], point[0], point[2]) && isLined(point[1], point[0], point[3])))
			cout << 0;
		else
		{
			cout << 1 << '\n';
			getIntersection(point[0], point[1], point[2], point[3]);
		}
	}
	else if (line1 <= 0 && line2 <= 0)
	{
		cout << 1 << '\n';
		getIntersection(point[0], point[1], point[2], point[3]);
	}
	else
		cout << 0;
}

int main()
{
	input();
	solve();
	return 0;
}