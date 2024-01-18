#define _CRT_SECURE_NO_WARNINGS 
#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 10001;
using namespace std;

int X, Y, D, T;
int jump;
double dist, remain, answer = INF;
double Case[5];
int main()
{
	scanf("%d %d %d %d", &X, &Y, &D, &T);
	dist = sqrt(X * X + Y * Y);
	jump = dist / D;
	remain = dist - jump * D;

	Case[0] = dist;
	Case[1] = remain + jump * T;
	Case[2] = (jump + 1) * D - dist + (jump + 1) * T;
	Case[3] = jump > 0 ? (jump + 1) * T : INF;
	Case[4] = jump <= 0 && dist < D ? 2 * T : INF;

	for (int i = 0; i < 5; ++i)
		answer = min(answer, Case[i]);

	printf("%.10lf", answer);

	return 0;
}