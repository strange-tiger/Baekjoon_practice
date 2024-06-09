#include <iostream>
#include <queue>
using namespace std;

int N, K;
priority_queue<long long, vector<long long>, greater<long long>> heap;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
}

void solve()
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			heap.push(i * j);

	while(K--)
		heap.pop();

	cout << heap.top();
}

int main()
{
	input();
	solve();
	return 0;
}