#include <iostream>
#include <queue>
#include <map>
using namespace std;

priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
map<int, int> leftNum;

int T, k, n;
char cmd;
const string Empty = "EMPTY";
void Insert()
{
	maxHeap.push(n);
	minHeap.push(n);
	++leftNum[n];
}

void maxHeapSync()
{
	while (!maxHeap.empty() && leftNum[maxHeap.top()] == 0)
		maxHeap.pop();
}

void minHeapSync()
{
	while (!minHeap.empty() && leftNum[minHeap.top()] == 0)
		minHeap.pop();
}

void Delete()
{
	switch (n)
	{
	case 1:
		maxHeapSync();
		
		if (maxHeap.empty())
			return;

		--leftNum[maxHeap.top()];
		maxHeap.pop();
		return;
	case -1:
		minHeapSync();

		if (minHeap.empty())
			return;

		--leftNum[minHeap.top()];
		minHeap.pop();
		return;
	default:
		return;
	}
}

void command()
{
	if (cmd == 'I')
		Insert();
	else if (cmd == 'D')
		Delete();
}

int main(void)
{
	cin >> T;

	while (T--)
	{
		leftNum.clear();
		while (!maxHeap.empty())
			maxHeap.pop();
		while (!minHeap.empty())
			minHeap.pop();

		cin >> k;

		while (k--)
		{
			cin >> cmd >> n;

			command();
		}

		maxHeapSync();
		minHeapSync();

		if (maxHeap.empty() || minHeap.empty())
			cout << Empty << '\n';
		else
			cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
	}

	return 0;
}