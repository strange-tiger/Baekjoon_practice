#include <iostream>
#include <algorithm>

using namespace std;

int num[1000001] = { 0 };

int main()
{
	
	int N;
	cin >> N;
	
	int cnt;
	for (int i = 0; i < N; i++)
	{
		cin >> cnt;
		num[i] = cnt;
	}

	sort(num[0], num[N]);

	for (int i = 0; i < N; i++)
	{
		cout << num[i] << '\n';
	}
	
	return 0;
}