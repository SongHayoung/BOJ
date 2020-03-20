#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int area[21][21];
int divd[21][21];
int popu[6],ans = 987654321,N,min,max;
int fRI() {
	register int N = gc(), r = 0;
	for (; 0x30>N || N>0x3A; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return r;
}
void calc(int x, int y, int d1, int d2) {
	memset(divd, 0, sizeof(divd));
	memset(popu, 0, sizeof(popu));
	register int i, j;
	for (i = 0; i <= d1; ++i) {
		if (!divd[x + i][y - i]) divd[x + i][y - i] = 5, popu[5] += area[x + i][y - i];
		if (!divd[x + d2 + i][y + d2 - i]) divd[x + d2 + i][y + d2 - i] = 5, popu[5] += area[x + d2 + i][y + d2 - i];
	}
	for (i = 0; i <= d2; ++i) {
		if (!divd[x + i][y + i]) divd[x + i][y + i] = 5, popu[5] += area[x + i][y + i];
		if (!divd[x + d1 + i][y - d1 + i]) divd[x + d1 + i][y - d1 + i] = 5, popu[5] += area[x + d1 + i][y - d1 + i];
	}
	for(i = 1; i < x+d1; ++i)
		for (j = 1; j <= y; ++j) {
			if (divd[i][j]) break;
			divd[i][j] = 1;
			popu[1] += area[i][j];
		}
	for (i = 1; i <= x + d2; ++i)
		for (j = N; j > y; --j) {
			if (divd[i][j]) break;
			divd[i][j] = 2;
			popu[2] += area[i][j];
		}
	for (i = x + d1; i <= N; ++i)
		for (j = 1; j < y-d1+d2; ++j) {
			if (divd[i][j]) break;
			divd[i][j] = 3;
			popu[3] += area[i][j];
		}
	for(i = x + d2 + 1; i <= N; ++i)
		for (j = N; j >= y - d1 + d2; --j) {
			if (divd[i][j]) break;
			divd[i][j] = 4;
			popu[4] += area[i][j];
		}
	for(i = x; i < x+d1+d2; ++i)
		for (j = y-d1; j < y+d2; ++j) {
			if (divd[i][j]) continue;
			popu[5] += area[i][j];
		}
	min = popu[1], max = popu[1];
	for (i = 2; i <= 5; ++i) {
		min = min > popu[i] ? popu[i] : min;
		max = max > popu[i] ? max : popu[i];
	}
	ans = ans > max - min ? max - min : ans;
}
int main() {
	N = fRI();
	register int y, x, d1, d2;
	for (x = 1; x <= N; ++x)
		for (y = 1; y <= N; ++y)
			area[x][y] = fRI();
	for(y = 2; y < N; ++y)
		for(x = 1; x < N-1; ++x)
			for(d1 = 1; 1<=y-d1; ++d1)
				for (d2 = 1; x + d1 + d2 <= N && y + d2 <= N; ++d2) 
						calc(x, y, d1, d2);
	printf("%d", ans);
}
