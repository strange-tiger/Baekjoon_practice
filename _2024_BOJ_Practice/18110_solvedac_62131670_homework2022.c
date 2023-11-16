/* 제출번호 : 62131670 아이디 : homework2022 */
#include <stdio.h>

int main() {
	int n = 0, cur = 0, i = 0, tmp = 0, sum = 0;
	int leftExclude = 0, rightExclude = 0;
	int opinion[31] = { 0, };
	char buf[900001] = { 0, };

	scanf("%d", &n);

	if (n == 0) {
		printf("0\n");
		return 0;
	}

	fread(buf, 1, 900001, stdin);
	cur = 1; // 맨앞에는 '\n'
	for (i = 0; i < n; i++) {
		tmp = buf[cur] - '0';
		cur++;
		if (buf[cur] != '\n') {
			tmp = tmp * 10 + buf[cur] - '0';
			cur++;
		}
		cur++;
		opinion[tmp]++;
	}

	leftExclude = (int)(n * 0.15 + 0.5);
	rightExclude = leftExclude;
	n -= (leftExclude + rightExclude);

	for (i = 1; i <= 30; i++) {
		if (opinion[i] <= leftExclude) {
			leftExclude -= opinion[i];
			opinion[i] = 0;
		}
		else {
			opinion[i] -= leftExclude;
			break;
		}
	}

	for (i = 30; i >= 1; i--) {
		if (opinion[i] <= rightExclude) {
			rightExclude -= opinion[i];
			opinion[i] = 0;
		}
		else {
			opinion[i] -= rightExclude;
			break;
		}
	}

	sum = 0;
	for (int i = 1; i <= 30; i++) {
		sum += opinion[i] * i;
	}

	printf("%d\n", (int)((double)sum / n + 0.5));

	return 0;
}