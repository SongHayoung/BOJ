#include <stdio.h>
#define gc() getchar_unlocked()
#define FFF(a,b) ((a<<3)+(a<<1)+(b&0b1111));
int ans[32769] = {0, };
void f(int c, int d, int s){
	if (c > 32769||!d) return;
	ans[c]++;
	for (register int i = s; i*i <= 32769 - c; i++)  f(c + i * i, d - 1, i);
}
int fRI() {
	int ret = 0, N = gc();
	for (; 0x30>N || N>0x3A; N = gc());
	for (; 0x30 <= N && N <= 0x3A; N = gc()) ret = FFF(ret, N)
		return ret;
}
int main(void){
    register int cache;
	f(0, 5, 1);
	while (cache=fRI())	printf("%d\n", ans[cache]);
}
