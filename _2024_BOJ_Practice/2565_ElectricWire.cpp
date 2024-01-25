#include <iostream>
#define MAX 501
using namespace std;

int N, temp, correct = 0;
int i, j;
int wire[MAX] = { 0 };
int L[MAX] = { 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> temp >> wire[temp];

	for (i = 1; i < MAX; ++i)
	{
		L[i] = 1;
		
		if (wire[i] == 0)
			continue;

		for (j = 1; j < i; ++j)
		{
			if (wire[i] > wire[j])
			{
				L[i] = L[i] > (L[j] + 1) ? L[i] : (L[j] + 1);
			}
		}

		correct = correct < L[i] ? L[i] : correct;
	}

	cout << N - correct;

	return 0;
}