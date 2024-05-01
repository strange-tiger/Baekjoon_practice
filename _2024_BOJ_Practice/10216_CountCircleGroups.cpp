#include <iostream>
#include <string.h>
using namespace std;

int T, N, answer;
int enemy[3001][3];
int parent[3001];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
}

void testcase()
{
	memset(enemy, 0, sizeof(enemy));
	memset(parent, 0, sizeof(parent));

	cin >> N;
	answer = N;

	for (int i = 0; i < N; ++i)
	{
		cin >> enemy[i][0] >> enemy[i][1] >> enemy[i][2];
		parent[i] = i;
	}
}

int find(int i)
{
	if (parent[i] == i)
		return i;
	else
		return parent[i] = find(parent[i]);
}

void merge(int a, int b)
{
	int A = find(a);
	int B = find(b);

	if (A < B)
		parent[B] = A;
	else
		parent[A] = B;
}

long long range;
long long dist, diff1, diff2;
void solve()
{
	while (T--)
	{
		testcase();

		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				range = enemy[i][2] + enemy[j][2];
				range *= range;

				diff1 = enemy[i][0] - enemy[j][0];
				diff2 = enemy[i][1] - enemy[j][1];
				dist = diff1 * diff1 + diff2 * diff2;

				if (range >= dist && find(i) != find(j))
				{
					merge(i, j);
					--answer;
				}
			}
		}

		cout << answer << '\n';
	}
}

int main()
{
	input();
	solve();
	return 0;
}