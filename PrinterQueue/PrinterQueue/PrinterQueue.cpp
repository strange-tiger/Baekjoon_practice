#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>

bool comp(int& l, int& r)
{
	return l > r;
}

int T, N, M;
std::deque<int> doc;
std::deque<int> doc_max;
int main()
{
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &N, &M);

		int imp;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &imp);
						
			doc.push_back(imp);
			doc_max.push_back(imp);
		}
		sort(doc_max.begin(), doc_max.end(), comp);

		int cnt = 0;
		int now = 0;
		int max = doc_max.front();
		while (!(doc_max.front() == doc.front() && 0 == M))
		{

			now = doc.front();
			if (max == now)
			{
				doc.pop_front();
				doc_max.pop_front();
				cnt++;
				M--;
				max = doc_max.front();
			}
			else
			{
				doc.push_back(now);
				doc.pop_front();
				M == 0 ? M = (int)doc.size() - 1 : M--;
			}
		}

		printf("%d\n", cnt + 1);

		doc.clear();
		doc_max.clear();
	}
	return 0;
}