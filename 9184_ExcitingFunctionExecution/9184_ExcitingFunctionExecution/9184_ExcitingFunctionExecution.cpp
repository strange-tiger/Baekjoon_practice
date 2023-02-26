#include <iostream>
using namespace std;

int a, b, c;
int w[101][101][101] = { 0 };
void W()
{
	int A, B, C;
	for (int i = -50; i < 21; ++i)
	{
		for (int j = -50; j < 21; ++j)
		{
			for (int k = -50; k < 21; ++k)
			{
				A = i + 50;
				B = j + 50;
				C = k + 50;

				if (i <= 0 || j <= 0 || k <= 0)
					w[A][B][C] = 1;
				else if (i < j && j < k)
					w[A][B][C] = w[A][B][C - 1] + w[A][B - 1][C - 1] - w[A][B - 1][C];
				else
					w[A][B][C] = w[A - 1][B][C] + w[A - 1][B - 1][C] + w[A - 1][B][C - 1] - w[A - 1][B - 1][C - 1];
			}
		}
	}

	for (int i = 21; i < 51; ++i)
	{
		for (int j = 21; j < 51; ++j)
		{
			for (int k = 21; k < 51; ++k)
			{
				A = i + 50;
				B = j + 50;
				C = k + 50;

				if (i <= 0 || j <= 0 || k <= 0)
					w[A][B][C] = 1;
				else if (i > 20 || j > 20 || k > 20)
					w[A][B][C] = w[70][70][70];
				else if (i < j && j < k)
					w[A][B][C] = w[A][B][C - 1] + w[A][B - 1][C - 1] - w[A][B - 1][C];
				else
					w[A][B][C] = w[A - 1][B][C] + w[A - 1][B - 1][C] + w[A - 1][B][C - 1] - w[A - 1][B - 1][C - 1];
			}
		}
	}
}

int main(void)
{
	W();

	cin >> a >> b >> c;
	
	while (a != -1 || b != -1 || c != -1)
	{
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w[a + 50][b + 50][c + 50] << '\n';

		cin >> a >> b >> c;
	}

	return 0;
}