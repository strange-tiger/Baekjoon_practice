#include <iostream>
#include <cmath>
using namespace std;

double x, y, c, answer;
double h1, h2, base;
double high, low;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> c;
}

void solve()
{
	low = 0;
	high = min(x, y);

	while (high - low > 0.001)
	{
		base = (high + low) / 2.0;

		h1 = sqrt(x * x - base * base);
		h2 = sqrt(y * y - base * base);
		
		if (h1 * h2 / (h1 + h2) >= c)
		{
			answer = base;
			low = base;
		}
		else
			high = base;
	}
	
	cout << fixed;
	cout.precision(3);
	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}