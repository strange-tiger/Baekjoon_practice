#include <iostream>
#include <utility>
#include <cmath>
#define P pair<double, double>
using namespace std;

int N;
double answer = 0;
P dot[10000];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> dot[i].first >> dot[i].second;
}

double ccw(P a, P b, P c)
{
	double outer = a.first * b.second + b.first * c.second + c.first * a.second;
	outer -= (b.first * a.second + c.first * b.second + a.first * c.second);
	return outer / 2;
}

void solve()
{
	for (int i = 1; i < N; ++i)
		answer += ccw(dot[0], dot[i - 1], dot[i]);
	cout << fixed;
	cout.precision(1);
	cout << abs(answer);
}

int main()
{
	input();
	solve();
	return 0;
}