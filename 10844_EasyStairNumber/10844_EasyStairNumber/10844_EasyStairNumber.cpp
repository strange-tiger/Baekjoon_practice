#include <iostream>
using namespace std;

int N;
int cnt[100][10]; // cnt[a][b] : 마지막 수가 b인 길이 a + 1의 계단 수
const int BILL = 1000000000;
int main(void)
{
	cin >> N;

	cnt[0][0] = 0;
	for (int i = 1; i < 10; ++i)
	{
		cnt[0][i] = 1;
	}

	for (int i = 1; i < N; ++i)
	{
		cnt[i][0] = cnt[i - 1][1];
		cnt[i][9] = cnt[i - 1][8];
		for (int j = 1; j < 9; ++j)
			cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j + 1]) % BILL;
	}

	int result = 0;
	for (int count : cnt[N - 1])
	{
		result += count;
		result %= BILL;
	}

	cout << result;

	return 0;
}