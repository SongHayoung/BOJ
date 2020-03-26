#include <stdio.h>
char b[1000];
void m(int n) {
	int c = n, i = 999;
	while (b[i]) {
		b[i] = ((b[i] - 48) * 2 + c) + 48;
		if (48>b[i])	b[i] += 10, c = -1;
		else if (b[i] > 57)	b[i] -= 10, c = 1;
		else c = 0;
		--i;
	}
	if (c) b[i] = 49;
}
void print() {
	for (int i = 0; i < 1000; ++i)
		if (b[i])
			putchar(b[i]);
}
int main(void) {
	int N;
	b[999] = 48;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i)
		i & 1 ? m(1) : m(-1);
	print();
}
