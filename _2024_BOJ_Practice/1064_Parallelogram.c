#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double MaxPeri(double a, double b, double c)
{
	if (a < b && a < c)
		return (b + c) * 2;
	else if (b < a && b < c)
		return (c + a) * 2;
	else
		return (a + b) * 2;
}

double MinPeri(double a, double b, double c)
{
	if (a > b && a > c)
		return (b + c) * 2;
	else if (b > a && b > c)
		return (c + a) * 2;
	else
		return (a + b) * 2;
}


int main(void)
{
	double x1, y1, x2, y2, x3, y3;
	double result;
	double len[3];

	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	
	if (abs((y2 - y1) * (x3 - x2)) == abs((y3 - y2) * (x2 - x1)))
		printf("-1.0");
	else
	{
		len[0] = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		len[1] = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
		len[2] = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

		result = MaxPeri(len[0], len[1], len[2]) - MinPeri(len[0], len[1], len[2]);
		printf("%.16lf", result);
	}

	return 0;
}