#include <iostream>
using namespace std;

int N, S, i, j;
int arr[50] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	cin >> S;

	for (i = 0; i < N && S > 0; ++i)
	{
		int Max = arr[i];
		int MaxI = i;

		for (j = i + 1; j < N && j <= i + S; ++j)
		{
			if (Max < arr[j])
			{
				Max = arr[j];
				MaxI = j;
			}
		}
		S -= MaxI - i;

		while (MaxI > i)
		{
			arr[MaxI] = arr[MaxI - 1];
			--MaxI;
		}
		arr[i] = Max;
	}

	for (i = 0; i < N; ++i)
		cout << arr[i] << ' ';

	return 0;
}