#include <iostream>
using namespace std;

int N, M;
int sequence[8];
void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
			cout << sequence[i] << ' ';

		cout << '\n';

		return;
	}

	int i = depth == 0 ? 0 : sequence[depth - 1] - 1;
	for (i; i < N; ++i)
	{
		sequence[depth] = i + 1;

		dfs(depth + 1);
	}
}

int main(void)
{
	cin >> N >> M;

	dfs(0);

	return 0;
}