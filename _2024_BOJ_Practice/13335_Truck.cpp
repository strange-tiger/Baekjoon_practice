#include <iostream>
#include <queue>
using namespace std;

int n, w, L, i, truck;
int sum = 0, answer = 0;
queue<int> trucks;
queue<int> onBridge;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w >> L;

	for (i = 0; i < n; ++i)
	{
		cin >> truck;
		trucks.push(truck);
	}

	while (n--)
	{
		if (onBridge.size() == w)
		{
			sum -= onBridge.front();
			onBridge.pop();
		}

		if (trucks.front() + sum <= L)
		{
			onBridge.push(trucks.front());
			sum += trucks.front();
			trucks.pop();
		}
		else
		{
			onBridge.push(0);
			++n;
		}

		++answer;
	}

	answer += w;

	cout << answer;

	return 0;
}