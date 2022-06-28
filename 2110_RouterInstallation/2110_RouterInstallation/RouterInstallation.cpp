#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int N, C, answer = 0;
int x[200000];
int main()
{
	// 1. ���� ������ �������� ������ �Է� �޴´�.
	scanf("%d %d", &N, &C);

	// 2. ���� ��ǥ�� �Է� �޴´�.
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x[i]);
	}

	// 3. ������ ������ �Ÿ��� ���ϱ� ���� ���� ��ǥ�� �����Ѵ�.
	std::sort(x, x + N);
	

	// 4. ���� �˻��� �� ������ ���� ������ ������ ������ �Ÿ�
	//    => [1, x[N - 1]]
	// -  ������ �ϴ� �ִ�� ��´�.
	//    -> ���ǿ� �� ������ ���ܵǵ��� �ϸ� �ȴ�.
	int s = 1, e = x[N - 1] + 1;

	while (s < e)
	{
		// 4-1. �߾Ӱ��� ���� �ĺ��� ���Ѵ�.
		// s : 1, e : 10, m : 5
		int m = (s + e) / 2;

		// 4-2. ������ m �Ÿ���ŭ ����߷� �����⸦ ��ġ�� �� �ִ��� Ȯ���Ѵ�.
		//		=> ������ m �Ÿ���ŭ ����߷��� ��, �� ���� �����Ⱑ �ʿ����� ����Ѵ�.
		int count = 1;
		int prevRouterPosition = 0; // ���� �������� ��ġ ��ġ

		for (int i = 1; i < N; ++i)
		{
			if (x[i] - x[prevRouterPosition] >= m)
			{
				++count;
				prevRouterPosition = i;
			}
		}

		if (count < C)
		{
			e = m;
		}
		else
		{
			// 4-3. �ִ� ���� �ֽ�ȭ
			if (answer < m)
			{
				answer = m;
			}

			// 4-4. �� ã�� �� �ִ��� ���� ����
			s = m + 1;
		}
	}

	// 5. �ִ� �Ÿ��� ����Ѵ�.
	printf("%d", answer);

	return 0;
} // �ּ��� ���� �ڵ�