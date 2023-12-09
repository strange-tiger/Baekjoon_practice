#include <iostream>
using namespace std;

int num, idx = 0;
int node[10001];
void PostorderTraversal(int start, int end)
{
	if (start >= end)
		return;

	idx = start + 1;
	for (idx = start + 1; idx < end; ++idx)
		if (node[start] < node[idx])
			break;

	PostorderTraversal(start + 1, idx);
	PostorderTraversal(idx, end);
	cout << node[start] << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> num)
		node[idx++] = num;

	PostorderTraversal(0, idx);

	return 0;
}