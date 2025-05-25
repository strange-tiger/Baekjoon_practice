// 2696_Median.cpp
#include <iostream>
#include <queue>
#include <vector>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int T, M, middle, num;
void Solve()
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	vector<int> ans;
	cin >> M;
	cin >> middle;
	ans.push_back(middle);

	for (int i = 1; i < M; ++i)
	{
		cin >> num;

		if (middle > num)
		{
			maxHeap.push(num);
		}
		else
		{
			minHeap.push(num);
		}

		if (i % 2 == 0)
		{
			if (maxHeap.size() > minHeap.size())
			{
				minHeap.push(middle);
				middle = maxHeap.top();
				maxHeap.pop();
			}
			else if (maxHeap.size() < minHeap.size())
			{
				maxHeap.push(middle);
				middle = minHeap.top();
				minHeap.pop();
			}
			ans.push_back(middle);
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i % 10 == 0 && i != 0)
		{
			cout << '\n';
		}
		cout << ans[i] << ' ';
	}
}

int main()
{
	fastio;

	cin >> T;
	while (T--)
	{
		Solve();
		cout << '\n';
	}
	return 0;
}