#include <iostream>
#include <string>
using namespace std;

string input;
string num = "";
int answer = 0;
bool isMinus = false;
void calculate()
{
	if (isMinus)
		answer -= stoi(num);
	else
		answer += stoi(num);

	num.clear();
}

int main(void)
{
	cin >> input;

	int size = input.size();

	for (char ch : input)
	{
		if (ch == '-' || ch == '+')
			calculate();
		else
			num += ch;

		if (ch == '-')
			isMinus = true;
	}
	calculate();

	cout << answer;

	return 0;
}