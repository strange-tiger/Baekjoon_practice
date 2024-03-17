#include <iostream>
#include <queue>
using namespace std;

int N, tmp;
int sTmp, bTmp;
priority_queue<int> small;
priority_queue<int, vector<int>, greater<int>> big;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--)
	{
		cin >> tmp;

		if (big.size() == small.size())
			small.push(tmp);
		else
			big.push(tmp);

		if (!big.empty() && !small.empty() && big.top() < small.top())
		{
			bTmp = big.top();
			sTmp = small.top();

			big.pop();
			small.pop();

			big.push(sTmp);
			small.push(bTmp);
			
		}

		cout << small.top() << '\n';
	}

	return 0;
}