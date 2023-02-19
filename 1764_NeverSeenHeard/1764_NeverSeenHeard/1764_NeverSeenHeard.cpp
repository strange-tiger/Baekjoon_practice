#include <iostream>
#include <queue>
#include <map>
using namespace std;

void insertionSort(string* arr, int num)
{
	string tmp;

	for (int i = 0; i < num - 1; ++i)
	{
		for (int j = i + 1; j > 0 && arr[j].compare(arr[j - 1]) < 0; --j)
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}
	}
}

int N, M, i, cnt = 0;
string name;
map <string, bool> neverSeen;
string neverHeard[500000];
queue<string> neverSeenHeard;
int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M;

	for (i = 0; i < N; ++i)
	{
		cin >> name;
		neverSeen[name] = true;
	}

	for (i = 0; i < M; ++i)
	{
		cin >> name;
		neverHeard[i] = name;
	}

	insertionSort(neverHeard, M);

	for (i = 0; i < M; ++i)
	{
		if (neverSeen[neverHeard[i]])
		{
			++cnt;
			neverSeenHeard.push(neverHeard[i]);
		}
	}

	cout << cnt << '\n';

	while (!neverSeenHeard.empty())
	{
		cout << neverSeenHeard.front() << '\n';
		neverSeenHeard.pop();
	}

	return 0;
}