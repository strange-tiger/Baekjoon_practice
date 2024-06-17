#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;

int N;
int cnt[MAX];
int course[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		cnt[i] = cnt[i - 1] + 1;
		course[i] = i - 1;

		if (i % 3 == 0 && cnt[i] > cnt[i / 3] + 1)
		{
			cnt[i] = min(cnt[i], cnt[i / 3] + 1);
			course[i] = i / 3;
		}
		if (i % 2 == 0 && cnt[i] > cnt[i / 2] + 1)
		{
			cnt[i] = cnt[i / 2] + 1;
			course[i] = i / 2;
		}
	}

	cout << cnt[N] << '\n';

	for (int i = N; i > 0;)
	{
		cout << i << ' ';
		i = course[i];
	}
	
	return 0;
}