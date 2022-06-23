#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int N;
int num;
stack<int> A;
stack<int> A_max;
stack<int> NGE;
int main()
{
	scanf("%d", &N);
#pragma region Max를_스택에_저장_Inspired_By_이재혁_leehuk0622
	
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		A.push(num);
	}

	while (!A.empty())
	{
		if (A_max.empty())
		{
			NGE.push(-1);
		}
		else if (A_max.top() > A.top())
		{
			NGE.push(A_max.top());
		}
		else if (A_max.top() <= A.top())
		{
			A_max.pop();
			continue;
		}
		A_max.push(A.top());
		A.pop();
	}

	while (!NGE.empty())
	{
		printf("%d ", NGE.top());
		NGE.pop();
	}

	return 0;

#pragma endregion
#pragma region 이진호_시간초과_두_스택의_비교
	//for (int i = 0; i < N; ++i)
	//{
	//	scanf("%d", &num);
	//	A.push(num);
	//	_A.push(num);
	//}

	//A.pop();
	//NGE.push_back(-1);

	//for (int i = 1; i < N; ++i)
	//{
	//	int ans = -1;
	//	// A 3 5 2 
	//	//_A 3 5 2 7
	//	int here = A.top();
	//	int size = NGE.size();
	//	
	//	if (A.size() != _A.size())
	//	{
	//		if (here < _A.top())
	//		{
	//			ans = _A.top();				
	//		}
	//		else if (here >= _A.top())
	//		{
	//			for (int j = size - 1; j >= 0; --j)
	//			{
	//				int temp = NGE[j];
	//				if (here < temp)
	//				{
	//					ans = temp;
	//					break;
	//				}
	//			}
	//		}

	//		_A.pop();
	//	}
	//	A.pop();
	//	NGE.push_back(ans);
	//}

	//for (int i = N - 1; i >= 0; --i)
	//{
	//	printf("%d ", NGE[i]);
	//}
#pragma endregion
}