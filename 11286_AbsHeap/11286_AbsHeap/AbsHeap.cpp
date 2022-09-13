#include <cstdio>
#include <vector>
using namespace std;

class Abs
{
public:
	Abs() = default;
	Abs(int _val)
		: val(_val)
	{
		if (_val < 0)
		{
			abs = -1 * _val;
		}
		else
		{
			abs = _val;
		}
	}
	int abs;
	int val;
};

vector<Abs> arr;
void Swap(int& left, int right)
{
	Abs temp;

	temp = arr[left - 1];
	arr[left - 1] = arr[right - 1];
	arr[right - 1] = temp;

	left = right;
}

int N, x;
int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &x);
		if (x != 0)
		{
			Abs X(x);
			arr.push_back(X);

			int index = arr.size();

			while (index > 1)
			{
				int parent = index / 2;

				if (arr[parent - 1].abs < X.abs)
				{
					break;
				}

				if (arr[parent - 1].abs == X.abs && arr[parent - 1].val < x)
				{
					break;
				}

				Swap(index, parent);
			}
		}
		else if (!arr.empty())
		{
			printf("%d\n", arr.front().val);
			arr[0] = arr.back();
			arr.pop_back();

			int size = arr.size();
			int index = 1;

			while (index < size)
			{
				int left = index * 2;
				int right = left + 1;

				if (left > size)
				{
					break;
				}

				int child = left;
				if (right <= size)
				{
					if (arr[right - 1].abs < arr[left - 1].abs)
						child = right;
					if (arr[right - 1].abs == arr[left - 1].abs && arr[right - 1].val < arr[left - 1].val)
						child = right;
				}

				if (arr[index - 1].abs < arr[child - 1].abs)
				{
					break;
				}

				if (arr[index - 1].abs == arr[child - 1].abs && arr[index - 1].val < arr[child - 1].val)
				{
					break;
				}

				Swap(index, child);
			}
		}
		else
		{
			printf("0\n");
		}
	}

	return 0;
}