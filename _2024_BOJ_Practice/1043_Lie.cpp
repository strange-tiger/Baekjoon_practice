#include <iostream>
#include <vector>
using namespace std;

int N, M;
int knowTruth;
int parent[53]; 
// 각 번호를 그룹 이름으로, 만난 사람을 원소로 갖는 그룹을 만든다.
// 0번은 진실을 아는 사람
int temp;
vector<int> party[53];
int partyNum;

int lie;

// 유니온 파인드(Union Find) : 각 원소가 속해있는 집합을 구별하고 찾기 위한 방법
int findParent(int x)
{
	if (parent[x] != x)
		return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int a, int b)
{
	int x = findParent(a);
	int y = findParent(b);

	if (x != y)
	{
		if (x < y) // 그룹 번호가 더 작은 쪽으로 합친다.
			parent[y] = x;
		else
			parent[x] = y;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	cin >> knowTruth;

	for (int i = 0; i <= N; ++i)
		parent[i] = i;

	while (knowTruth--)
	{
		cin >> temp;
		parent[temp] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> partyNum;
		cin >> temp;
		party[i].push_back(temp);

		for (int j = 1; j < partyNum; ++j)
		{
			cin >> temp;
			party[i].push_back(temp);
			merge(party[i][0], party[i][j]);
		}
	}

	lie = M;

	for (int i = 0; i < M; ++i)
	{
		for (int j : party[i])
		{
			if (findParent(parent[j]) == 0)
			{
				--lie;
				break;
			}
		}
	}

	cout << lie;

	return 0;
}