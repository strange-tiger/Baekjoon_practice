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
	L l = mid - 1, r = mid;
	L width = 2;
	L lh = 0, rh = 0, minh = min(h[l], h[r]);
	L area = width * minh;

	if (mid == left)
		return h[mid];

	while (l >= 0 && r < n)
	{
		if (l > 0)
			lh = h[l - 1];
		else
			lh = 0;

		if (r < n - 1)
			rh = h[r + 1];
		else
			rh = 0;

		minh = min(minh, max(lh, rh));

		if (lh > rh)
			--l;
		else
			++r;

		++width;
		area = max(area, width * minh);
	}
	return max(max(getRect(left, mid - 1), getRect(mid, right)), area);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n, n != 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> h[i];
		cout << getRect(0, n) << '\n';
	}

	return 0;
}