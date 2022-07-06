#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
N, F; main() { scanf("%d %d", &N, &F); printf("%02d", (F - N % F + N % 100) % F); }