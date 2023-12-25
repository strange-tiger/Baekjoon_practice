#include <iostream>
#include <queue>
using namespace std;

long long int A, B;
long long int num;
int cnt = -1;
queue<pair<long long int, int>> q;
long long int bfs(long long int a, long long int b)
{
	q.push({ a, 1 });

	while (!q.empty())
	{
		num = q.front().first;
		int count = q.front().second;
		q.pop();

		if (num == b)
		{
			cnt = count;
			return cnt;
		}

		long long int num1 = 2 * num;
		if (num1 <= B)
		{
			q.push({ num1, count + 1 });
		}

		long long int num2 = num * 10 + 1;
		if (num2 <= B)
		{
			q.push({ num2, count + 1 });
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	cout << bfs(A, B);

	return 0;
}