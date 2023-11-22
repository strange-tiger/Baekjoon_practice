#include <iostream>
#include <stack>
using namespace std;

int N = 0;
int B = 0;
int i = 0;
int temp = 0;
int cnt = 0;
stack<char> result;

int main()
{
	cin >> N >> B;

	while (N)
	{
		temp = N % B;
		N /= B;

		if (temp < 10)
			temp += 48;
		else if (temp >= 10)
			temp += 55;

		result.push((char)temp);
	}

	while (!result.empty())
	{
		cout << result.top();
		result.pop();
	}

	return 0;
}