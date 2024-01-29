#include <iostream>
#define MAX 200001
using namespace std;

int N, M, K;
int before, after;
bool able = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	while (M--)
	{
		cin >> K;

		before = MAX;
		after = MAX;

		while (K--)
		{
			before = after;
			cin >> after;
			if (before < after)
			{
				able = false;
			}
		}
	}

	if (able)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';

	return 0;
}