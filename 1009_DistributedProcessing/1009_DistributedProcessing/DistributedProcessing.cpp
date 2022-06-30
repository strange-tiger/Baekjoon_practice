#include <iostream>
using namespace std;

int T, a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--)
	{
		cin >> a >> b;

		int table[5] = { 0 };
		int db = 1;
		for (int i = 1; i <= 4; ++i)
		{
			db *= a;
			if (db % 10 != 0)
				table[i] = db % 10;
			else
				table[i] = 10;
		}

		table[0] = table[4];

		cout << table[b % 4] << "\n";
	}
}