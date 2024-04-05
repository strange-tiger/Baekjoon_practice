#include <iostream>
#define A 300
#define B 60
#define C 10
using namespace std;

int T;
int btn[3] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	if (T % C > 0)
		cout << -1;
	else
	{
		btn[0] = T / A;
		btn[1] = (T % A) / B;
		btn[2] = (T % B) / C;

		cout << btn[0] << ' ' << btn[1] << ' ' << btn[2];
	}

	return 0;
}