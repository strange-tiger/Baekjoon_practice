#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int* arr, int num)
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i + 1; j > 0 && arr[j] > arr[j - 1]; --j)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

int N, k;
int cutLine;
int main(void)
{
	cin >> N;
	cin >> k;

	int* arr = new int[N];

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	insertionSort(arr, N);

	cutLine = arr[k - 1];
	cout << cutLine;

	delete[] arr;
	return 0;
}