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
	bool order;
	while (T--)
	{
		cin >> cmd;
		cin >> n;
		order = true;

		do
		{
			cin >> digit;
			if (isdigit(digit))
			{
				num += digit;
			}
			else if ('[' != digit)
			{
				if (!num.empty())
				{
					x.push_back(stoi(num));
					num = "";
				}
			}
		} while (']' != digit);

		isError = false;
		size = cmd.size();
		xsize = x.size();
		for (int i = 0; i < size; ++i)
		{
			if ('R' == cmd[i])
			{
				order = !order;
			}
			else if ('D' == cmd[i])
			{
				if (x.empty())
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}

				if (order)
				{
					x.pop_front();
				}
				else
				{
					x.pop_back();
				}
				--xsize;
			}
		}

		if (!isError)
		{
			xsize = x.size();
			cout << '[';
			if (order)
			{
				for (int i = 0; i < xsize; ++i)
				{
					cout << x[i];
					if (i != xsize - 1) cout << ',';
				}
			}
			else
			{
				for (int i = xsize - 1; i >= 0; --i)
				{
					cout << x[i];
					if (i != 0) cout << ',';
				}
			}
			
			cout << ']';
			cout << '\n';
		}

		x.clear();
	}

	return 0;
}