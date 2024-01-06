#include <iostream>
#include <deque>
using namespace std;

int N, M;
int i, j, num;
bool qs[100000];
deque<int> dq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> qs[i];
	}
	for (i = 0; i < N; ++i)
	{
		cin >> num;
		if (!qs[i])
			dq.push_back(num);
	}

	cin >> M;

	while(M--)
	{
		cin >> num;

		dq.push_front(num);
		cout << dq.back() << ' ';
		dq.pop_back();
	}

	return 0;
}