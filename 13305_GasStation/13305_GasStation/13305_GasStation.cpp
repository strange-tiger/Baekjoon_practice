#include <iostream>
#include <vector>
using namespace std;

int N, i;
long long answer = 0;
long long Min = 1000000001;
int Distance[100000];
int price[100000];
int main(void)
{
	cin >> N;

	for (i = 0; i < N - 1; ++i)
		cin >> Distance[i];

	for (i = 0; i < N - 1; ++i)
		cin >> price[i];

	for (i = 0; i < N - 1; ++i)
	{
		if (Min > price[i])
			Min = price[i];

		answer += (long long)(Distance[i] * Min);
	}

	cout << answer;

	return 0;
}