#include <iostream>
#include <string>
#include <stack>
using namespace std;

int value = 1;
int result = 0;
string br;
stack<char> st;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> br;

	for (int i = 0; i < br.length(); ++i)
	{
		if (br[i] == '(')
		{
			value *= 2;
			st.push(br[i]);
		}
		else if (br[i] == '[')
		{
			value *= 3;
			st.push(br[i]);
		}
		else if (br[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				result = 0;
				break;
			}
			if (br[i - 1] == '(')
			{
				result += value;
			}

			value /= 2;
			st.pop();
		}
		else if (br[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				result = 0;
				break;
			}
			if (br[i - 1] == '[')
			{
				result += value;
			}

			value /= 3;
			st.pop();
		}
	}

	if (!st.empty())
		result = 0;

	cout << result;

	return 0;
}