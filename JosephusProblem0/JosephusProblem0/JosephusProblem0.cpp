#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int N, K;
std::queue<int> people;
int main()
{
	scanf("%d %d", &N, &K);

	int i = 0;
	while (N--)
	{
		i++;
		people.push(i);
	}

	printf("<");
	
	do
	{
		for (int i = 1; i < K; ++i)
		{
			people.push(people.front());
			people.pop();
		}

		printf("%d", people.front());
		people.pop();

	}while (!people.empty() && printf(", "));
	printf(">");

	// without queue

	return 0;
}