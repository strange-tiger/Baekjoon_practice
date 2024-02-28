#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define INF 2147483647;
using namespace std;

int N, M, hNum, chNum;
int answer = INF;
bool chosen[13] = { false };
vector<pair<int, int>> house;
vector<pair<int, int>> chPlace;
vector<pair<int, int>> chosenPlace;

int CalculateChickenDist()
{
	int sum = 0;

	for (int i = 0; i < hNum; ++i)
	{
		int x = house[i].first;
		int y = house[i].second;
		int dist = INF;

		for (int j = 0; j < M; ++j)
		{
			int cx = chosenPlace[j].first;
			int cy = chosenPlace[j].second;

			dist = min(dist, abs(x - cx) + abs(y - cy));
		}
		sum += dist;
	}

	return sum;
}

void ChooseChicken(int idx, int cnt)
{
	if (cnt == M)
	{
		answer = min(answer, CalculateChickenDist());
		return;
	}

	for (int i = idx; i < chNum; ++i)
	{
		if (chosen[i])
			continue;

		chosen[i] = true;
		chosenPlace.push_back(chPlace[i]);

		ChooseChicken(i, cnt + 1);

		chosen[i] = false;
		chosenPlace.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> temp;

			if (temp == 1)
				house.push_back({ j, i });
			else if (temp == 2)
				chPlace.push_back({ j, i });
		}
	}
	hNum = house.size();
	chNum = chPlace.size();

	ChooseChicken(0, 0);

	cout << answer;

	return 0;
}