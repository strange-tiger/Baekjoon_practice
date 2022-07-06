#include <iostream>
using namespace std;

int N, F;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> F;

	N /= 100;
	N *= 100;

	N += (N % F == 0 ? 0 : (F - N % F));

	if (N % 100 < 10)
	{
		cout << 0 << N % 10;
	}
	else
	{
		cout << N % 100;
	}

	return 0;
}
