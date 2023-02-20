#include <iostream>
using namespace std;

int N, M;
int sequence[8];
bool visit[8] = { false };
void dfs(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i)
			cout << sequence[i] << ' ';

		cout << '\n';

		return;
	}

	int i = depth == 0 ? 0 : sequence[depth - 1];
	for (i; i < N; ++i)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		sequence[depth] = i + 1;

		dfs(depth + 1);

		visit[i] = false;
	}
}

int main(void)
{
	cin >> N >> M;

	dfs(0);

	return 0;
}