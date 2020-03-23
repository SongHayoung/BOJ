#include <stdio.h>
#include <memory.h>
#define SWAP(x, y) {(x)^=(y)^=(x)^=(y);}
#define gc() getchar_unlocked()
short laptop[40][40];
short sticker[10][10];
short R, C;
int fRI() {
	int N = gc(), ret = 0;
	for (; N<48 || N>57; N = gc());
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return ret;
}
void Rotate90() {
	short Rsticker[10][10] = { 0, };
	for (short i = 0; i < R; ++i)
		for (short j = 0; j < C; ++j)
			Rsticker[j][R - 1 - i] = sticker[i][j];
	SWAP(R, C);
	memcpy(sticker, Rsticker, sizeof(sticker));
}
int main() {
	register short N = fRI(), M = fRI(), K = fRI(), answer, i, j, sti, stj, put_flag, flag, rotate, stk;
	for (stk = 0; stk < K; ++stk) {
		R = fRI(); C = fRI();
		for (i = 0; i < R; ++i)
			for (j = 0; j < C; ++j)
				sticker[i][j] = fRI();
		put_flag = 0;
		for(rotate = 0; rotate < 4 && !put_flag; ++rotate) {
			for (i = 0; i <= N - R && !put_flag; ++i)
				for (j = 0; j <= M - C && !put_flag; ++j) {
					flag = 0;
					for (sti = 0; sti < R && !flag; ++sti)
						for (stj = 0; stj < C && !flag; ++stj)
							if (sticker[sti][stj] && laptop[i + sti][j + stj]) flag = 1;
					if (flag) continue;
					put_flag = 1;
					for (sti = 0; sti < R; ++sti)
						for (stj = 0; stj < C; ++stj) 
							if (sticker[sti][stj])	laptop[i + sti][j + stj] = 1, ++answer;
				}
			if(!put_flag) Rotate90();
		}
	}
	printf("%d", answer);
}
