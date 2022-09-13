#include <cstdio>
#include <vector>
using namespace std;

vector<int> arr;
void Swap(int& left, int right)
{
	int temp;

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
			arr.push_back(x);

			int index = arr.size();

			while (index > 1)
			{
				int parent = index / 2;

				if (arr[parent - 1] < x)
				{
					break;
				}

				Swap(index, parent);
			}
		}
		else if (!arr.empty())
		{
			printf("%d\n", arr.front());
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
				if (right <= size && arr[right - 1] < arr[left - 1])
				{
					child = right;
				}

				if (arr[index - 1] <= arr[child - 1])
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