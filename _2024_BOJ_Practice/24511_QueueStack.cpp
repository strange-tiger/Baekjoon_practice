#include <iostream>
using namespace std;

int N, M;
int i, j, temp;
int qs[100000];
int element[100000];
int input[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> qs[i];
	}
	for (i = 0; i < N; ++i)
	{
		cin >> element[i];
	}

	cin >> M;

	for (i = 0; i < M; ++i)
	{
		cin >> input[i];
	}

	for (i = 0; i < M; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			if (!qs[j])
			{
				temp = input[i];
				input[i] = element[j];
				element[j] = temp;
			}
		}

		cout << input[i] << ' ';
	}

	return 0;
}