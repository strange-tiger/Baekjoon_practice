#include <iostream>
#include <iostream>
using namespace std;

void insertionSort(string* arr, int num)
{
	string tmp;

	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i + 1; j > 0 && arr[j].compare(arr[j - 1]) < 0; --j)
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
}

bool binarySearch(string* arr, string str, int s, int e)
{
	int middle = (s + e) / 2;

	if (str.compare(*(arr + middle)) == 0)
	{
		return true;
	}
	else if (s == e)
	{
		return false;
	}
	else if (str.compare(*(arr + middle)) > 0)
	{
		s = middle + 1;
	}
	else if (str.compare(*(arr + middle)) < 0)
	{
		e = middle;
	}

	return binarySearch(arr, str, s, e);
}

int N, M;
int result = 0;
int main(void)
{
	cin >> N;
	cin >> M;

	string* S = new string[N];

	string* examine = new string[M];

	for (int i = 0; i < N; ++i)
		cin >> S[i];

	insertionSort(S, N);

	for (int i = 0; i < M; ++i)
		cin >> examine[i];

	for (int i = 0; i < M; ++i)
		if (binarySearch(S, examine[i], 0, N - 1))
			++result;

	cout << result;

	delete[] S;
	delete[] examine;

	return 0;
}