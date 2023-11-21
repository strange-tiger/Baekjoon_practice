#include <iostream>
using namespace std;

int i = 0;
int j = 0;
char temp;
char arr[5][15];

int main()
{
	for (i = 0; i < 5; ++i)
		cin >> arr[i];

	while (j < 15)
	{
		for (i = 0; i < 5; ++i)
			if (arr[i][j] != NULL)
				cout << arr[i][j];

		++j;
	}
}