#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;
int A[1001] = { 0 };
int B[1001] = { 0 };
long long cnt = 0;
vector<long long> sumA;
vector<long long> sumB;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}

	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> B[i];
		B[i] += B[i - 1];
	}
}

void solve()
{
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			sumA.push_back(A[j] - A[i]);

	for (int i = 0; i < M; ++i)
		for (int j = i + 1; j <= M; ++j)
			sumB.push_back(B[j] - B[i]);

	sort(sumA.begin(), sumA.end());
	sort(sumB.begin(), sumB.end());

	int s = 0, e = sumB.size() - 1;
	while (s < sumA.size() && e >= 0)
	{
		if (sumA[s] + sumB[e] > T)
			--e;
		else if (sumA[s] + sumB[e] < T)
			++s;
		else
		{
			int valA = sumA[s];
			int valB = sumB[e];
			long long cntA = 0;
			long long cntB = 0;

			while (s < sumA.size() && valA == sumA[s])
			{
				++s;
				++cntA;
			}

			while (e >= 0 && valB == sumB[e])
			{
				--e;
				++cntB;
			}

			cnt += cntA * cntB;
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