#include <iostream>
using namespace std;

int n[3];

void bubbleSort(int num[], int N)
{
	int tmp;
	for (int i = N - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (num[j] > num[j + 1])
			{
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}
}

void selectionSort(int num[], int N)
{
	int tmp, idx;
	for (int i = 0; i < N - 1; ++i)
	{
		idx = i;

		for (int j = i + 1; j < N; ++j)
		{
			if (num[idx] > num[j])
				idx = j;
		}

		if (i != idx)
		{
			tmp = num[i];
			num[i] = num[idx];
			num[idx] = tmp;
		}
	}
}

void insertionSort(int num[], int N)
{
	int tmp, j;
	for (int i = 1; i < N; ++i)
	{
		tmp = num[i];

		for (j = i - 1; j >= 0 && num[j] > tmp; --j)
		{
			num[j + 1] = num[j];
		}

		num[j + 1] = tmp;
	}
}

void sort(int num[], int N)
{
	insertionSort(num, 3);
}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; ++i)
		cin >> n[i];
}

void solve()
{
	sort(n, 3);

	for (int i : n)
		cout << i << ' ';
}

int main()
{
	input();
	solve();
	return 0;
}