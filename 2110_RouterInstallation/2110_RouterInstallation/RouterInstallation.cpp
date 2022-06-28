#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

int N, C, answer = 0;
int x[200000];
int main()
{
	// 1. 집의 개수와 공유기의 개수를 입력 받는다.
	scanf("%d %d", &N, &C);

	// 2. 집의 좌표를 입력 받는다.
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x[i]);
	}

	// 3. 공유기 사이의 거리를 구하기 위해 집의 좌표를 정렬한다.
	std::sort(x, x + N);
	

	// 4. 이진 검색을 할 범위는 가장 인접한 공유기 사이의 거리
	//    => [1, x[N - 1]]
	// -  범위는 일단 최대로 잡는다.
	//    -> 조건에 안 맞으면 제외되도록 하면 된다.
	int s = 1, e = x[N - 1] + 1;

	while (s < e)
	{
		// 4-1. 중앙값을 해의 후보로 정한다.
		// s : 1, e : 10, m : 5
		int m = (s + e) / 2;

		// 4-2. 실제로 m 거리만큼 떨어뜨려 공유기를 배치할 수 있는지 확인한다.
		//		=> 실제로 m 거리만큼 떨어뜨렸을 때, 몇 개의 공유기가 필요한지 계산한다.
		int count = 1;
		int prevRouterPosition = 0; // 직전 공유기의 설치 위치

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
			// 4-3. 최대 길이 최신화
			if (answer < m)
			{
				answer = m;
			}

			// 4-4. 더 찾을 수 있는지 범위 조절
			s = m + 1;
		}
	}

	// 5. 최대 거리를 출력한다.
	printf("%d", answer);

	return 0;
} // 최선문 교수 코드