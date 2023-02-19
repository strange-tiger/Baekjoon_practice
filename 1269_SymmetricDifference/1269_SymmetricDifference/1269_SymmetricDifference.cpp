#include <iostream>
#include <map>
using namespace std;

int numA, numB, key;
int intersectionCnt = 0;
int symDifferenceCnt = 0;
map <int, bool> group;
int main(void)
{
	cin >> numA >> numB;

	symDifferenceCnt = numA + numB;

	for (int i = 0; i < symDifferenceCnt; ++i)
	{
		cin >> key;
		
		if (group[key])
		{
			++intersectionCnt;
			group[key] = false;
		}
		else
			group[key] = true;
	}

	symDifferenceCnt -= 2 * intersectionCnt;

	cout << symDifferenceCnt;

	return 0;
}