#include <iostream>
using namespace std;

int N;
int Max = 0;
int cnt[51] = { 0 };
int height[51];
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
	return (double)(height[b] - height[a]) / (b - a);
}

void solve()
{
	for (int i = 0; i < N; ++i)
	{
		double tmpSlope;
		double maxSlope = -1e9;
		
		for (int j = i + 1; j < N; ++j)
		{
			tmpSlope = Slope(i, j);

			if (tmpSlope > maxSlope)
			{
				maxSlope = tmpSlope;
				++cnt[i];
				++cnt[j];
			}
		}

		Max = Max < cnt[i] ? cnt[i] : Max;
	}

	cout << Max;
}

int main()
{
	input();
	solve();
	return 0;
}