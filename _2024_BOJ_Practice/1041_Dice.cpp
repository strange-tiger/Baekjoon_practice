#include <iostream>
#include <algorithm>
using namespace std;

long long int N, answer = 0;
long long int dice[6];
long long int face[3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 6; ++i)
		cin >> dice[i];
	for (int i = 0; i < 3; ++i)
		face[i] = min(dice[i], dice[5 - i]);
	sort(face, face + 3);
	sort(dice, dice + 6);

	if (N == 1)
		for (int i = 0; i < 5; ++i)
			answer += dice[i];
	else
		answer = (5 * N * N - 8 * N + 4) * face[0] + (8 * N - 8) * face[1] + 4 * face[2];

	cout << answer;

	return 0;
}