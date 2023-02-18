#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int* arr, int num)
{
	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i + 1; j > 0 && arr[j] < arr[j - 1]; --j)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

int arr[5];
int avg = 0, center = 0;
int main(void)
{
	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
		avg += arr[i];
	}
	avg /= 5;

	insertionSort(arr, 5);
	center = arr[2];

	cout << avg << '\n' << center;
	return 0;
}