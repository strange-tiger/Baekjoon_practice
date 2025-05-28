#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int N, i;

int main(void)
{
	fastio;
	cin >> N;
	for (i = 1; i <= N; i += 2)
	{
		cout << i << ' ';
	}

	if (N % 2 == 0)
	{
		i = N;
	}
	else
	{
		i = N - 1;
	}

	for (i; i >= 1; i -= 2)
	{
		cout << i << ' ';
	}
	return 0;
}