#include <stdio.h>
char buf[1000];
void multiply(int n) {
	int carry = n;
	int idx = 999;
	while (48 <= buf[idx] && buf[idx] <= 57) {
		buf[idx] = (((buf[idx]&0b1111)<<1)+carry)+48;
		if (48 > buf[idx])				buf[idx] += 10, carry = -1;
		else if (buf[idx] > 57)		buf[idx] -= 10, carry = 1;
		else							carry = 0;
		idx--;
	}
	if (carry) buf[idx] = 49;
}
void print() {
	for (int i = 0; i < 1000; ++i)
		if (48 <= buf[i] && buf[i] <= 57)
			putchar(buf[i]);
}
int main(void) {
	int N;
	buf[999] = 48;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i) {
		if (i & 1) multiply(1);
		else multiply(-1);
	}
	print();
}
