#include <iostream>
#include <cmath>
#define DIVIDED 1000000007
using namespace std;

long long int n;
double golden = (1 + sqrt(5)) / 2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	long long int answer = (long long int)(round((long double)(pow(golden, n) - pow(1 - golden, n)) / sqrt(5))) % DIVIDED;

	cout << answer;

	return 0;
}