#include <iostream>
using namespace std;

int N;
long long int pNum[91] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	pNum[0] = 0;
	pNum[1] = 1;
	for (int i = 2; i <= N; ++i)
		pNum[i] = pNum[i - 1] + pNum[i - 2];

	cout << pNum[N];

	return 0;
}