#include <stdio.h>
int main(void) {
	long long N, n = 2;
	int a = 1;
	scanf("%lld", &N);
	while (N + 1 > n*a) n <<= 1,++a;
	printf("%d", a-1);
}
