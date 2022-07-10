#include <iostream>
#include <algorithm>
using namespace std;

int N;
int p[1000] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> p[i];
	}

	sort(p, p + N);
	
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int cnt = N - i;
		for (int j = 0; j < cnt; ++j)
		{
			sum += p[i];
		}
	}

	cout << sum << '\n';

	return 0;
}