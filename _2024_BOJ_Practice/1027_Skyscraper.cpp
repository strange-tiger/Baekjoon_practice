#include <iostream>
using namespace std;

int N;
int cnt, Max = 0;
int height[50];
double slope;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> height[i];
}

double Slope(int a, int b)
{
	return (double)(height[a] - height[b]) / (a - b);
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		cnt = 0;
		double tmp;
		
		if (i > 0)
		{
			++cnt;
			slope = Slope(i, i - 1);
		}
		for (int j = i - 1; j >= 0; --j)
		{
			tmp = Slope(i, j);
			
			if (tmp > slope)
			{
				++cnt;
				slope = tmp;
			}
		}

		if (i < N - 1)
		{
			++cnt;
			slope = Slope(i + 1, i);
		}
		for (int j = i + 1; j < N; ++j)
		{
			tmp = Slope(j, i);

			if (tmp > slope)
			{
				++cnt;
				slope = tmp;
			}
		}

		Max = cnt > Max ? cnt : Max;
	}

	cout << Max;
}

int main()
{
	input();
	solve();
	return 0;
}