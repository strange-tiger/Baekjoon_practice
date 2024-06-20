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
	L l = mid - 1, r = mid;

	if (left == mid)
		return h[mid];

	while (l >= left and r <= right)
	{
		height = min(height, max(h[l], h[r]));
		
		if (h[l] > h[r])
			--l;
		else
			++r;

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
		for (int i = 0; i < n; ++i)
			cin >> h[i];
		cout << getRect(0, n) << '\n';
	}

	return 0;
}