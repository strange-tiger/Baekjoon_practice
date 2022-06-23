#include <iostream>
#include <algorithm>
using namespace std;

bool disc(const int& left, const int& right)
{
	return left > right;
}

int S(int* A, int* B, int N)
{
	int sum = 0;
	
	int i = 0;
	while (N--)
	{
		sum += A[i] * B[i];
		++i;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int* A = new int[N];
	int* B = new int[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N, disc);

	cout << S(A, B, N);

	delete[] A;
	delete[] B;

	return 0;
}