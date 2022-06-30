//
//	수식 : 경우의 수 = (의상 종류 1의 개수 + 1) * (종류 2의 개수 + 1) * ... * (종류 m의 개수 + 1) - 1
//
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define cnt first
#define type second

using namespace std;

int T, n;
string str[2];
vector<pair<int, string>> apparel;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			cin >> str[0] >> str[1];
			
			int size = apparel.size();
			for (int j = 0; j < size; ++j)
			{
				if (!apparel[j].type.compare(str[1]))
				{
					++apparel[j].cnt;
					break;
				}
				else if (j == size - 1)
				{
					apparel.push_back({ 1, str[1] });
				}
			}

			if (apparel.empty())
			{
				apparel.push_back({ 1, str[1] });
			}
		}

		int result = 1;
		for (int i = 0; i < apparel.size(); ++i)
		{
			result *= apparel[i].cnt + 1;
		}

		result -= 1;

		cout << result << "\n";
		apparel.clear();
	}

	return 0;
}