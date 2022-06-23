#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//1.int 배열 두 개에 저장 후 하나를 정렬, 여기서 이진 탐색으로 요소를 찾아
// 그 좌표를 출력하는 것으로 좌표 압축을 시도

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> vec1;
	vector<int> vec2;

	int num;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);

		vec1.push_back(num);

		vec2.push_back(num);
	}
	
	sort(vec2.begin(), vec2.end());

	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	
	/*int size = vec2.size();
	for (int i = 0; i < N; ++i)
	{
		if (vec1[i] <= vec2[size / 2])
		{
			for (int j = size / 2; j >= 0; --j)
			{
				if (vec1[i] == vec2[j])
				{
					if (j != 0 && vec1[i] != vec2[j - 1])
					{
						vec1[i] = j;
					}
					else if (j == 0)
					{
						vec1[i] = j;
					}
				}
			}
		}
		else if (vec1[i] > vec2[size / 2])
		{
			for (int j = size / 2; j < size; ++j)
			{
				if (vec1[i] == vec2[j])
				{
					vec1[i] = j;
				}
			}
		}
	}*/

	/*int size = vec2.size();
	for (int i = 0; i < N; ++i)
	{
		int start = 0, end = size - 1;
		while (end >= start)
		{
			if (vec2[size / 2] < vec1[i])
			{
				start = size / 2 + 1;
			}
			else
			{
				end = size / 2 - 1;
			}
		}
		vec1[i] = start;
	}*/

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", lower_bound(vec2.begin(), vec2.end(), vec1[i]) - vec2.begin());
		// printf("%d ", vec1[i]);
	}
	
	return 0;
}