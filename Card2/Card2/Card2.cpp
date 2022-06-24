#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

int N;
std::queue<int> deck;
int main()
{
	scanf("%d", &N);

	int i = 0;
	while (N--)
	{
		i++;
		deck.push(i);
	}

	while (1 < deck.size())
	{
		deck.pop();
		deck.push(deck.front());
		deck.pop();
	}

	printf("%d", deck.front());

	return 0;

	// without queue

}