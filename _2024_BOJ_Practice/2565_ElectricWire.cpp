#include <iostream>
#include <utility>
#include <algorithm>
#define MAX 501
#define Pair pair<int, int>
using namespace std;

int N, correct = 0;
int i, j;
int L[MAX] = { 0 };
Pair wire[MAX];

bool Cmp(Pair A, Pair B)
{
	return A.first < B.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (i = 0; i < N; ++i)
		cin >> wire[i].first >> wire[i].second;

	sort(wire, wire + N, Cmp);

	for (i = 0; i < N; ++i)
	{
		L[i] = 1;
		
		for (j = 0; j < i; ++j)
			if (wire[i].second > wire[j].second)
				L[i] = max(L[i], L[j] + 1);

		correct = max(correct, L[i]);
	}

	cout << N - correct << '\n';

	return 0;
}