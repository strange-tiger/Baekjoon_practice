#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

// 

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> A;
	vector<int> _A;
	vector<int> NGE;

	int num;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		A.push_back(num);
		_A.push_back(num);
	}

	for (int i = 0; i < N; ++i)
	{
		bool isNGE = true;
		for (int j = i + 1; j < N; ++j)
		{
			if (A[i] < _A[j])
			{
				NGE.push_back(_A[j]);
				break;
			}
			else
			{
				isNGE = false;
			}
		}
		if (!isNGE)
		{
			NGE.push_back(-1);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", NGE[i]);
	}
	
	return 0;
}