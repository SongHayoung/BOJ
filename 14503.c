#include <stdio.h>
#define gc() getchar_unlocked()
int map[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int fRI() {
	int ret = 0, N = gc();
	for (; 0x30>N || N>0x3A; N = gc());
	for (; 0x30 <= N && N <= 0x3A; N = gc()) ret = (ret << 3) + (ret << 1) + (N & 0b1111);
	return ret;
}
int main(int argc, char** argv){
	register int N = fRI(), M = fRI(), y = fRI(), x = fRI(), dir = fRI(), ans = 0, f, j;
	for (register int i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			map[i][j] = fRI();
	while (1) {
		if (!map[y][x]) { map[y][x] = 2; ans++; }
		f = 0;
		for (j = 1; j <= 4; j++) {
			dir = (dir + 3) % 4;
			if (!map[y + dy[dir]][x + dx[dir]]) {
				y += dy[dir];
				x += dx[dir];
				f = 1;
				break;
			}
		}
		if (f) continue;
		y = y + dy[(dir + 2) % 4];
		x = x + dx[(dir + 2) % 4];
		if (map[y][x]&1) { printf("%d", ans); return 0; }
	}
}
