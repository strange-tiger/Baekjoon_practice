#include <iostream>
#include <string>
using namespace std;

bool setCheck[20] = { false };
int M;
string cmd;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M;

	int x;
	while (M--)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> x;
			if (!setCheck[x - 1])	
				setCheck[x - 1] = !setCheck[x - 1];
		}
		if (cmd == "remove")
		{
			cin >> x;
			if (setCheck[x - 1])
				setCheck[x - 1] = !setCheck[x - 1];
		}
		if (cmd == "check")
		{
			cin >> x;
			cout << setCheck[x - 1] << "\n";
		}
		if (cmd == "toggle")
		{
			cin >> x;
			setCheck[x - 1] = !setCheck[x - 1];
		}
		if (cmd == "all")
		{
			for (int i = 0; i < 20; ++i)
				setCheck[i] = true;
		}
		if (cmd == "empty")
		{
			for (int i = 0; i < 20; ++i)
				setCheck[i] = false;
		}
	}

	return 0;
}