// 2075_NthNumber.cpp
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N, all, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	all = N * N;
	while (all--)
	{
		cin >> n;
		pq.push(n);
		if (pq.size() > N)
			pq.pop();
	}

	cout << pq.top();
	return 0;
}