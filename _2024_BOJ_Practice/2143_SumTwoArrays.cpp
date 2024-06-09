#include <iostream>
#include <set>
using namespace std;

int T, N, M, cnt = 0;
int sumA[1001];
int sumB[1001];
multiset<int> setA;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cin >> N;
	sumA[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> sumA[i];
		sumA[i] += sumA[i - 1];
	}

	cin >> M;
	sumB[0] = 0;
	for (int i = 1; i <= M; ++i)
	{
		cin >> sumB[i];
		sumB[i] += sumB[i - 1];
	}
}

void solve()
{
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			setA.insert(sumA[j] - sumA[i]);

	int numB;
	for (int i = 0; i < M; ++i)
	{
		for (int j = i + 1; j <= M; ++j)
		{
			numB = sumB[j] - sumB[i];

			if (setA.count(T - numB))
				cnt += setA.count(T - numB);
		}
	}

	cout << cnt;
}

int main()
{
	input();
	solve();
	return 0;
}