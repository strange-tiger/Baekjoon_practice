#include <iostream>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

int N;
double answer = 0;
pair<double, double> polygon[36];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> polygon[i].first >> polygon[i].second;
}

double length(pair<double, double> a, pair<double, double> b)
{
	double dx = a.first - b.first;
	double dy = a.second - b.second;

	return sqrt(dx * dx + dy * dy);
}

double area(int i, int j, int k)
{
	double a = length(polygon[i], polygon[j]);
	double b = length(polygon[j], polygon[k]);
	double c = length(polygon[k], polygon[i]);

	double s = (a + b + c) / 2;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void solve()
{
	for (int i = 0; i < N - 2; ++i)
		for (int j = i + 1; j < N - 1; ++j)
			for (int k = j + 1; k < N; ++k)
				answer = max(answer, area(i, j, k));

	cout.setf(ios::fixed);
	cout.precision(10);
	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}