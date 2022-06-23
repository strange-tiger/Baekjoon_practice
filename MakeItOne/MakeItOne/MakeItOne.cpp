#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	int cntCal = 0;
	int cal1 = 0;
	int cal2 = 0;
	
	int temp1 = N;
	while (temp1 != 1)
	{
		if (temp1 % 3 == 0)
		{
			temp1 /= 3;
			++cal1;
		}
		else if (temp1 % 3 == 1)
		{
			temp1--;
			++cal1;
		}
		else if (temp1 % 2 == 0)
		{
			temp1 /= 2;
			++cal1;
		}
		else
		{
			temp1--;
			++cal1;
		}
	}

	int temp2 = N;
	while (temp2 != 1)
	{
		if (temp2 % 3 == 0)
		{
			temp2 /= 3;
			++cal2;
		}
		else if (temp2 % 2 == 0)
		{
			temp2 /= 2;
			++cal2;
		}
		else
		{
			temp2--;
			++cal2;
		}
	}

	if (cal1 > cal2)
	{
		cntCal = cal2;
	}
	else
	{
		cntCal = cal1;
	}
	
	std::cout << cntCal;

	return 0;
}