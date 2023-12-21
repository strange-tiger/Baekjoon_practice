#include <iostream>
using namespace std;

int N;
int i, j, k;
int G[100][100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			cin >> G[i][j];

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			if (!G[i][j])
				G[i][j] = 100;

	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				G[j][k] = min(G[j][k], G[j][i] + G[i][k]);

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			if (G[i][j] == 100)
				cout << 0 << ' ';
			else
				cout << 1 << ' ';
		cout << '\n';
	}

	return 0;
}