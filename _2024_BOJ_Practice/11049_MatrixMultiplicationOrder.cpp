#include <iostream>
#define MAX 2147483647
using namespace std;

int N;
int mat[500][2];
int dp[500][500];

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> mat[i][0] >> mat[i][1];
	}
}

void solve()
{

}

int main()
{
	input();
	solve();
	return 0;
}