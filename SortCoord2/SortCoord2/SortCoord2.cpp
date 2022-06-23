#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else if (a.second == b.second)
	{
		if (a.first < b.first)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	int x = 0;
	int y = 0;

	vector<pair<int, int>> vec;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);

		vec.push_back(pair<int, int>(x, y));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", vec[i].first, vec[i].second);
	}

	return 0;
}