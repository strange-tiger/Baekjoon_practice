#include <iostream>
using namespace std;

int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	if (N % 2 == 1)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}