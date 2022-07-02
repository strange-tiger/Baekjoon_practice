#include <iostream>
using namespace std;

int N, r, c;
int cnt = 0;
void zfunc(int r, int c, int length)
{
	int half = length / 2;
	if (half == 0)
	{
		return;
	}

	int quarter = half * half;
	if (r >= 0 && r < half)
	{
		if (c >= 0 && c < half)
		{
			cnt += 0 * quarter;
			zfunc(r, c, half);
		}
		else
		{
			cnt += 1 * quarter;
			zfunc(r, c - half, half);
		}
	}
	else
	{
		if (c >= 0 && c < half)
		{
			cnt += 2 * quarter;
			zfunc(r - half, c, half);
		}
		else
		{
			cnt += 3 * quarter;
			zfunc(r - half, c - half, half);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> r >> c;

	int side = 1;
	while (N--)
	{
		side *= 2;
	}

	zfunc(r, c, side);
	cout << cnt;

	return 0;
}