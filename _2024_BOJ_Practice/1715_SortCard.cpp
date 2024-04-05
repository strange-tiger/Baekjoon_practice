#include <iostream>
#include <queue>
using namespace std;

int N;
int answer = 0, sum = 0, temp;
priority_queue<int, vector<int>, greater<int>> heap;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		heap.push(temp);
	}
}

void solve()
{
	while (heap.size() > 1)
	{
		sum = 0;

		sum += heap.top();
		heap.pop();
		sum += heap.top();
		heap.pop();
		
		answer += sum;
		heap.push(sum);
	}

	cout << answer;
}

int main()
{
	input();
	solve();
	return 0;
}