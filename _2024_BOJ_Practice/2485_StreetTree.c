#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, gcm, i;
int answer = 0;
int tree[100000] = { 0 };
int dist[100000] = { 0 };

int GCM(int A, int B)
{
	int less, more;

	if (A > B)
	{
		less = B;
		more = A;
	}
	else
	{
		less = A;
		more = B;
	}

	while (1)
	{
		if (!(more % less))
		{
			break;
		}
		more = more % less;

		int temp;
		temp = more;
		more = less;
		less = temp;
	}

	return less;
}

int main()
{
	scanf("%d", &N);

	for (i = 0; i < N; ++i)
		scanf("%d", tree + i);
	for (i = 1; i < N; ++i)
		dist[i - 1] = tree[i] - tree[i - 1];

	gcm = GCM(dist[0], dist[1]);
	for (i = 2; i < N - 1; ++i)
	{
		int temp = GCM(dist[i - 1], dist[i]);

		gcm = GCM(gcm, temp);
	}

	for (i = 0; i < N - 1; ++i)
		answer += dist[i] / gcm - 1;

	printf("%d", answer);

	return 0;
}