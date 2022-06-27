#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long; // 오버플로우를 방지하기 위해 long long 타입 사용

ll K, N, M = 0;
ll lan[10000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	// 1. K와 N을 입력 받는다.
	cin >> K >> N;

	// 2. 갖고 있는 랜선의 길이를 입력 받는다.
	for (ll i = 0; i < K; ++i)
	{
		cin >> lan[i];

		if (M < lan[i])
		{
			M = lan[i];
		}
	}

	// 3. 이진 검색
	// 범위 : 자를 수 있는 랜선의 길이
	// [1, M + 1)
	// [1, 458)
	ll s = 1, e = M + 1;
	ll result = 0;
	while (s < e)
	{
		// 해가 될 수 있는 후보
		ll m = (s + e) / 2;
		// s : 1, e : 458, m : 229

		//m의 길이로 잘랐을 때 얻을 수 있는 랜선의 개수
		ll  count = 0;
		for (int i = 0; i < K; ++i)
		{
			count += lan[i] / m;
		}

		// 해
		if (count >= N)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}
		else
			e = m;
	}

	cout << result;
}