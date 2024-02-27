#include <iostream>
#include <algorithm>
using namespace std;

int N, temp;
int Max[3], Min[3], in[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> Max[0] >> Max[1] >> Max[2];
	Min[0] = Max[0];
	Min[1] = Max[1];
	Min[2] = Max[2];

	while (--N)
	{
		cin >> in[0] >> in[1] >> in[2];

		temp = Max[1];
		Max[1] = in[1] + max(Max[0], max(temp, Max[2]));
		Max[0] = in[0] + max(Max[0], temp);
		Max[2] = in[2] + max(Max[2], temp);

		temp = Min[1];
		Min[1] = in[1] + min(Min[0], min(temp, Min[2]));
		Min[0] = in[0] + min(Min[0], temp);
		Min[2] = in[2] + min(Min[2], temp);
	}

	cout << max(Max[0], max(Max[1], Max[2])) << ' ' << min(Min[0], min(Min[1], Min[2]));

	return 0;
}