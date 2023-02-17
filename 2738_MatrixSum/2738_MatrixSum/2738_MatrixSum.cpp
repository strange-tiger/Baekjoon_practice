#include <iostream>
using namespace std;

int N, M;
int main(void)
{
	cin >> N;
	cin >> M;

	int** sum = new int*[N];
	for (int i = 0; i < N; ++i)
		sum[i] = new int[M];
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> sum[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			int tmp;
			cin >> tmp;

			sum[i][j] += tmp;
		}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << sum[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < N; ++i)
		delete[] sum[i];
	delete[] sum;

	return 0;
}