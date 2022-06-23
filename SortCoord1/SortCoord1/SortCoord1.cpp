#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y;

	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

bool compare(point& a, point& b)
{
	if (a.x < b.x)
	{
		return true;
	}
	else if (a.x == b.x)
	{
		if (a.y < b.y)
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
		
	vector<point> vec;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);

		vec.push_back(point(x, y));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", vec[i].x, vec[i].y);
	}

	return 0;
}