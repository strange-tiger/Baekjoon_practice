#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>

int main()
{
#pragma region 스택_사용_버전
	int n;
	scanf("%d", &n);

	int* seq = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", seq + i);
	}

	char* str = new char[2 * n];
	int i = 0;
	int cnt = 0;
	int disCnt = 0;
	bool isAble = true;

	std::stack<int> stk;
	while (n--)
	{
		for (cnt; cnt < seq[i]; ++cnt)
		{
			str[cnt + disCnt] = '+';
			stk.push(cnt + 1);
		}
		str[cnt + disCnt] = '-';
		++disCnt;

		if (stk.top() != seq[i])
		{
			isAble = false;
			break;
		}
		stk.pop();

		++i;
	}

	if (!isAble)
	{
		printf("NO");
	}
	else
	{
		for (int j = 0; j < cnt + disCnt; ++j)
		{
			printf("%c\n", str[j]);
		}
	}

	delete[] str;
	delete[] seq;

	return 0;
#pragma endregion

#pragma region 스택_미사용_버전
//	// 실패
//#include <cstdio>
//
//	int main()
//	{
//		int n;
//		scanf("%d", &n);
//
//		int* seq = new int[n];
//		for (int i = 0; i < n; ++i)
//		{
//			scanf("%d", seq + i);
//		}
//
//		char* str = new char[2 * n];
//		int i = 0;
//		int cnt = 0;
//		int disCnt = 0;
//		bool isAble = true;
//
//		while (n--)
//		{
//			for (cnt; cnt < seq[i]; ++cnt)
//			{
//				str[cnt + disCnt] = '+';
//			}
//
//			if (cnt > disCnt && seq[i] <= cnt - disCnt)
//			{
//				isAble = false;
//				break;
//			}
//			str[cnt + disCnt] = '-';
//			++disCnt;
//
//			++i;
//		}
//
//		if (!isAble)
//		{
//			printf("NO");
//		}
//		else
//		{
//			for (int j = 0; j < cnt + disCnt; ++j)
//			{
//				printf("%c\n", str[j]);
//			}
//		}
//
//		delete[] str;
//		delete[] seq;
//
//		return 0;
//	}
#pragma endregion
}