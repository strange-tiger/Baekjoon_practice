#include <iostream>
using namespace std;

int T, N;
int dist = 12;
string students[32];

string standardMBTI = "ESTJ";
int MBTI_differ(string mbti, int i)
{
	return mbti[i] == standardMBTI[i] ? 0 : 1;
}

int calculateDist(string a, string b, string c)
{
	int dif = 0;

	for (int i = 0; i < 4; ++i)
		dif += abs(MBTI_differ(a, i) - MBTI_differ(b, i));
	for (int i = 0; i < 4; ++i)
		dif += abs(MBTI_differ(b, i) - MBTI_differ(c, i));
	for (int i = 0; i < 4; ++i)
		dif += abs(MBTI_differ(c, i) - MBTI_differ(a, i));
	return dif;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> T;

	while (T--)
	{
		cin >> N;

		if (N > 32)
		{
			cout << 0 << '\n';
			continue;
		}

		for (int i = 0; i < N; ++i)
			cin >> students[i];

		for (int i = 0; i < N - 2; ++i)
			for (int j = i + 1; j < N - 1; ++j)
				for (int k = j + 1; k < N; ++k)
					dist = min(dist, calculateDist(students[i], students[j], students[k]));

		cout << dist << '\n';
		dist = 12;
	}
	return 0;
}