#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T, N;
int answer, a, b;
vector<pair<int, int>> rec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> N;
		rec.clear();

		for (int i = 0; i < N; ++i)
		{
			cin >> a >> b;
			rec.push_back({ a, b });
		}
		sort(rec.begin(), rec.end());

		int better = 0;
		answer = 1;

		for (int i = 1; i < N; ++i)
		{
			if (rec[better].second > rec[i].second)
			{
				++answer;
				better = i;
			}
		}

		cout << answer << '\n';
	}

	return 0;
}