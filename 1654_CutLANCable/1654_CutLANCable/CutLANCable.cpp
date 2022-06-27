#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long; // �����÷ο츦 �����ϱ� ���� long long Ÿ�� ���

ll K, N, M = 0;
ll lan[10000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	// 1. K�� N�� �Է� �޴´�.
	cin >> K >> N;

	// 2. ���� �ִ� ������ ���̸� �Է� �޴´�.
	for (ll i = 0; i < K; ++i)
	{
		cin >> lan[i];

		if (M < lan[i])
		{
			M = lan[i];
		}
	}

	// 3. ���� �˻�
	// ���� : �ڸ� �� �ִ� ������ ����
	// [1, M + 1)
	// [1, 458)
	ll s = 1, e = M + 1;
	ll result = 0;
	while (s < e)
	{
		// �ذ� �� �� �ִ� �ĺ�
		ll m = (s + e) / 2;
		// s : 1, e : 458, m : 229

		//m�� ���̷� �߶��� �� ���� �� �ִ� ������ ����
		ll  count = 0;
		for (int i = 0; i < K; ++i)
		{
			count += lan[i] / m;
		}

		// ��
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