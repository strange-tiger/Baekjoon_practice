#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double pi = 3.14159265358979323846;
double X1, Y1, R1, X2, Y2, R2;

double distance(double a1, double a2, double b1, double b2)
{
	return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;
	cout << fixed;
	cout.precision(3);

	if (R1 < R2)
	{
		swap(X1, X2);
		swap(Y1, Y2);
		swap(R1, R2);
	}
}

void solve()
{
	double d = distance(X1, Y1, X2, Y2);

	if (d >= R1 + R2)
		cout << 0.000;
	else if (d + R2 <= R1)
		cout << R2 * R2 * pi;
	else
	{
		double theta1 = acos((R1 * R1 + d * d - R2 * R2) / (2 * R1 * d));
		double theta2 = acos((R2 * R2 + d * d - R1 * R1) / (2 * R2 * d));

		double S1 = R1 * R1 * (theta1 - sin(2 * theta1) / 2);
		double S2 = R2 * R2 * (theta2 - sin(2 * theta2) / 2);
		
		cout << S1 + S2;
	}
}

int main()
{
	input();
	solve();
	return 0;
}