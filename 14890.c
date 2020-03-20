#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
short map[100][100];
short used[100];
short N, L , ans = 0;
short fRI() {
	register short N = gc(), r = 0;
	for (; 0x30>N || N>0x3A; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return r;
}
int main() {
	N = fRI(); L = fRI();
	register short i, j, k, flag = 0;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j)
			map[i][j] = fRI();
		memset(used, 0, sizeof(short)*N);
		for (j = 0; j < N - 1; ++j) {
			if (map[i][j] < map[i][j + 1]) {
				if (map[i][j] + 1 != map[i][j + 1]) { flag = 1; break; }
				for (k = j; k > j - L; --k) {
					if (k < 0 || map[i][j] ^ map[i][k] || used[k]) { flag = 1; break; }
					else used[k] ^= 1;
				}
			}
			else if (map[i][j] > map[i][j + 1]) {
				if (map[i][j] != map[i][j + 1] + 1) { flag = 1; break; }
				for (k = j + 1; k <= j + L; ++k) {
					if (k == N || map[i][j + 1] ^ map[i][k] || used[k]) { flag = 1; break; }
					else used[k] ^= 1;
				}
			}
			if (flag) break;
		}
		if (!flag)	++ans;
		else flag ^= 1;
	}
	for (j = 0; j < N; ++j) {
		flag = 0;
		memset(used, 0, sizeof(short)*N);
		for (i = 0; i < N- 1; ++i) {
			if (map[i][j] < map[i+1][j]) {
				if (map[i][j] + 1 != map[i+1][j]) { flag = 1; break; }
				for (k = i; k > i - L; --k) {
					if (k < 0 || map[i][j] ^ map[k][j]||used[k]) { flag = 1; break; }
					else used[k] ^= 1;
				}
			}
			else if (map[i][j] > map[i+1][j]) {
				if (map[i][j] != map[i+1][j]+1) { flag = 1; break; }
				for (k = i + 1; k <= i + L; ++k) {
					if (k == N || map[i+1][j] ^ map[k][j]||used[k]) { flag = 1; break; }
					else used[k] ^= 1;
				}
			}
			if (flag) break;
		}
		if (!flag)	++ans;
		else flag ^= 1;
	}
	printf("%d", ans);
}
