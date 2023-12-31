#include <iostream>
using namespace std;

int H, W;
int total = 0;
int bottom[500] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> H >> W;

	for (int i = 0; i < W; ++i)
		cin >> bottom[i];

	for (int i = 1; i < W - 1; ++i)
	{
		int left = 0;
		int right = 0;

		for (int j = 0; j < i; ++j)
			left = max(left, bottom[j]);
		for (int j = W - 1; j > i; --j)
			right = max(right, bottom[j]);
		total += max(0, min(left, right) - bottom[i]);
	}

	cout << total;

	return 0;
}