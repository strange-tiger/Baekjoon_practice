#include <iostream>
using namespace std;

int a, b, c;
int w[21][21][21] = { 0 };
int W(int i, int j, int k)
{
	if (i <= 0 || j <= 0 || k <= 0)
		return 1;
	
	if (i > 20 || j > 20 || k > 20)
		return W(20, 20, 20);
	
	if (w[i][j][k])
		return w[i][j][k];

	if (i < j && j < k)
	{
		w[i][j][k] = W(i, j, k - 1) + W(i, j - 1, k - 1) - W(i, j - 1, k);
		return w[i][j][k];
	}
	
	w[i][j][k] = W(i - 1, j, k) + W(i - 1, j - 1, k) + W(i - 1, j, k - 1) - W(i - 1, j - 1, k - 1);
	return w[i][j][k];
}

int main(void)
{
	w[0][0][0] = 1;

	cin >> a >> b >> c;
	
	while (a != -1 || b != -1 || c != -1)
	{
		cout << "w(" << a << ", " << b << ", " << c << ") = " << W(a, b, c) << '\n';

		cin >> a >> b >> c;
	}

	return 0;
}