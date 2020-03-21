#include <stdio.h>
#define gc() getchar()
int nums[11];
int susicks[4];
int imax = -987654321, imin = 987654321, N;
int fRI() {
	register int N = gc(), r = 0;
	for (; 0x30>N || N>0x3A; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return r;
}
void DFS(int idx, int cur) {
	if (idx == N) {
		imax = imax > cur ? imax : cur;
		imin = imin > cur ? cur : imin;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (susicks[i]) {
			--susicks[i];
			switch (i) {
			case 0: DFS(idx + 1, cur + nums[idx]); break;
			case 1: DFS(idx + 1, cur - nums[idx]); break;
			case 2: DFS(idx + 1, cur * nums[idx]); break;
			case 3: DFS(idx + 1, cur / nums[idx]); break;
			}
			++susicks[i];
		}
	}
}
int main(int argc, char** argv) {
	N = fRI();
	for (int i = 0; i < N; ++i)
		nums[i] = fRI();
	for (int i = 0; i < 4; ++i)
		susicks[i] = fRI();
	DFS(1, nums[0]);
	printf("%d\n%d", imax, imin);

}
