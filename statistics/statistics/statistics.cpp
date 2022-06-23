#define _CRT_SECURE_NO_WARNIGS
#include <cstdio>
#include <algorithm>

int main()
{
	int N;
	scanf_s("%d", &N);

	// ������
	int sum = 0;
	// �߾Ӱ�
	int* findMedian = new int[N];
	// �ֺ�
	int cnt[8001] = { 0 };
	// ����
	int min = 4001;
	int max = -4001;
	
	int num;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &num);

		sum += num;
		findMedian[i] = num;
		++cnt[num + 4000];

		if (min > num)
			min = num;
		if (max < num)
			max = num;
	}
	
	// ������
	double average = (double)sum / (float)N;
	if (sum < 0)
	{
		if (average > -0.6)
		{
			average = 0.0;
		}
	}

	// �߾Ӱ�
	int median = 0;
	std::sort(findMedian, findMedian + N);
	median = findMedian[N / 2];

	// �ֺ�
	int mode = 4001;
	int modeLess = 4001;
	int maxCnt = 0;
	
	for (int i = 0; i < 8001; i++)
	{
		int candNum = i - 4000;

		if (maxCnt < cnt[i])
		{
			maxCnt = cnt[i];
			mode = candNum;
			modeLess = candNum;
		}
		else if (maxCnt == cnt[i])
		{
			if (modeLess > candNum)
			{
				mode = modeLess;
				modeLess = candNum;
			}
			else if (modeLess == mode)
			{
				mode = candNum;
			}
		}
	}

	// ����
	int range = max - min;

	printf("%.0lf\n%d\n%d\n%d", average, median, mode, range);

	delete[] findMedian;

	return 0;
}