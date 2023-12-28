#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sonA, sonB;
int momA, momB;
int less, more;
int son, mom;
int main()
{
	scanf("%d %d", &sonA, &momA);
	scanf("%d %d", &sonB, &momB);

	son = (sonA * momB + sonB * momA);
	mom = momA * momB;

	if (son > mom)
	{
		less = mom;
		more = son;
	}
	else
	{
		less = son;
		more = mom;
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

	son /= less;
	mom /= less;

	printf("%d %d\n", son, mom);

	return 0;
}