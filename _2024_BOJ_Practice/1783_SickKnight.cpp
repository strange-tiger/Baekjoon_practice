#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	if (N == 1)
		cout << 1;
	else if (N == 2)
		cout << min(4, (M + 1) / 2);
	else if (M < 7)
		cout << min(4, M);
	else
		cout << M - 2;
	return 0;
}