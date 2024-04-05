#include <iostream>
#include <cmath>
#define L long long
using namespace std;

L S, N;
double num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	num = sqrt(2 * S);
	N = (L)num - 1;

	while (N * (N + 1) <= 2 * S)
		++N;
	cout << N - 1;
}