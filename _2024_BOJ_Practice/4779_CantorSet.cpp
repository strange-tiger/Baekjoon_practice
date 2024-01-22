#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, len;
string ans;

void Cantor(int s, int e)
{
	if (e - s == 1)
		return;
	int mark = (e - s) / 3;

	for (int i = s + mark; i < e - mark; ++i)
		ans[i] = ' ';
	
	Cantor(s, s + mark);
	Cantor(e - mark, e);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while ((!cin.eof()) && cin >> N)
	{
		len = pow(3, N);
		ans.clear();
		ans.append(len, '-');

		Cantor(0, len);
		cout << ans << '\n';
	}

	return 0;
}