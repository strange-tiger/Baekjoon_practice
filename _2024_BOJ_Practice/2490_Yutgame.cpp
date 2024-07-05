#include <iostream>
using namespace std;

int yut, sum = 0, T = 3, tmp;
char res[5] = {'D', 'C', 'B', 'A', 'E'};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(T--)
	{
		sum = 0;
		for (int i = 0; i < 4; ++i)
		{
			cin >> tmp;
			sum += tmp;
		}

		cout << res[sum] << '\n';
	}

	return 0;
}