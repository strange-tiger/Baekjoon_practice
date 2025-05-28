// 28065_SWSequence
#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int N;
int main()
{
	fastio;

	cin >> N;

	if (N % 2 == 0)
	{
		for (int i = 1; i <= N / 2; ++i)
		{
			cout << N - i + 1 << ' ' << i << ' ';
		}
	}
	else
	{
		for (int i = 1; i <= N / 2; ++i)
		{
			cout << i << ' ' << N - i + 1 << ' ';
		}
		cout << N / 2 + 1;
	}

	return 0;
}