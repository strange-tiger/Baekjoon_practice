#include <iostream>
#include <string>
#include <deque>
#include <utility>
using namespace std;

int T, n;
deque<int> x;
string cmd;
string num = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	char digit;
	int cnt, size, xsize;
	bool isError;
	while (T--)
	{
		cin >> cmd;
		cin >> n;
		
		cnt = 0;
		while (cnt < n)
		{
			cin >> digit;
			if (isdigit(digit))
			{
				num += digit;
			}
			else if ('[' != digit)
			{
				x.push_back(stoi(num));
				num = "";
				++cnt;
			}
		}

		isError = false;
		size = cmd.size();
		for (int i = 0; i < size; ++i)
		{
			if ('R' == cmd[i])
			{
				xsize = x.size();
				for (int j = 0; j < xsize / 2; ++j)
				{
					swap(x[j], x[xsize - 1 - j]);
				}
			}
			else if ('D' == cmd[i])
			{
				if (x.empty())
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}
				x.pop_front();
			}
		}

		if (!isError)
		{
			xsize = x.size();
			cout << '[';
			for (int i = 0; i < xsize; ++i)
			{
				cout << x[i];
				if (i != xsize - 1) cout << ',';
			}
			cout << ']';
			cout << '\n';
		}

		x.clear();
	}

	return 0;
}