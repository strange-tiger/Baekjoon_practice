#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int temp = num;
	int digit[10] = { 0 };
	
	int size = 0;
	while (temp)
	{
		digit[size] = temp % 10;
		temp /= 10;
		size++;
	}

	int cnt[10] = { 0 };
	for (int i = 0; i < size; i++)
	{
		cnt[digit[i]]++;
	}

	string str = "";
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			str += to_string(i);
		}
	}

	num = stoi(str);

	printf("%d", num);

	return 0;
}
