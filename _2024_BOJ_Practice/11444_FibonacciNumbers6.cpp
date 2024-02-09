#include <iostream>
#include <map>
#define DIVIDED 1000000007LL
#define L long long
using namespace std;

L n;
map <L, L> F;

L fibonacci(L num)
{
	if (num == 0)
		return 0;
	if (num == 1)
		return 1;
	if (num == 2)
		return 1;
	if (F.count(num) > 0)
		return F[num];

	if (num % 2 == 0)
	{
		L m = num / 2;
		L n1 = fibonacci(m - 1);
		L n2 = fibonacci(m);
		F[num] = (2LL * n1 * n2 + n2 * n2) % DIVIDED;
		return F[num];
	}
	else
	{
		L m = (num + 1) / 2;
		L n1 = fibonacci(m - 1);
		L n2 = fibonacci(m);
		F[num] = (n1 * n1 + n2 * n2) % DIVIDED;
		return F[num];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cout << fibonacci(n);

	return 0;
}