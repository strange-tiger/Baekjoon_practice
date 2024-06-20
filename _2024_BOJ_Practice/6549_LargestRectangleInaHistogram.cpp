#include <iostream>
#include <algorithm>
#define L long long
using namespace std;

int n;
L h[100001];

L getRect(L left, L right)
{
	L mid = (left + right) / 2;
	L height = h[mid];
	L area = h[mid];
	L l = mid - 1, r = mid + 1;

	if (left >= right - 1)
		return area;

	while (l > left || r < right)
	{
		if (l <= left || (r < right && h[l] <= h[r]))
		{
			height = min(height, h[r]);
			r++;
		}
		else
		{
			height = min(height, h[l]);
			l--;
		}
		L width = r - l - 1;
		area = max(area, width * height);
	}
	return max(max(getRect(left, mid), getRect(mid, right)), area);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n, n != 0)
	{
		for (int i = 1; i <= n; ++i)
			cin >> h[i];
		cout << getRect(0, n + 1) << '\n';
	}

	return 0;
}