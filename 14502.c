#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
short lab[8][8];
short dx[4] = { 0,1,0,-1 };
short dy[4] = { -1,0,1,0 };
short q[64][2];
short v[8][8];
short N, M, ans = 0, m_size = 0;
short fRI() {
	register short N = gc(), r = 0;
	for (; 0x30>N || N>0x3A; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (0x30 <= N);
	return r;
}
void DFS(short p_cnt, short choose) {
	if (choose == 3) {
		short size = m_size - 3;
		short lab_cpy[8][8];
		short qi, qe;
		memcpy(lab_cpy, lab, sizeof(lab_cpy));
		memset(v, 0, sizeof(v));
		for (short i = 0; i < N; ++i)
			for (short j = 0; j < M; ++j) {
				if (lab_cpy[i][j] == 2 && !v[i][j]) {
					v[i][j] ^= 1;
					q[0][0] = i;
					q[0][1] = j;
					qi = 1; qe = 0;
					while (qi != qe) {
						short cy = q[qe][0];
						short cx = q[qe][1];
						++qe;
						for (short k = 0; k < 4; ++k) {
							short ny = cy + dy[k];
							short nx = cx + dx[k];
							if (0 <= nx && nx < M && 0 <= ny && ny < N && !lab_cpy[ny][nx] && !v[ny][nx]) {
								q[qi][0] = ny;
								q[qi][1] = nx;
								lab_cpy[ny][nx] = 2;
								v[ny][nx] ^= 1;
								++qi;
								--size;
							}
						}
						if (m_size < ans) return;
					}

				}
			}
		ans = ans > size ? ans : size;
		return;
	}
	short cnt = 0;
	for (short i = 0; i < N; ++i)
		for (short j = 0; j < M; ++j) {
			++cnt;
			if (!lab[i][j] && cnt>p_cnt) {
				lab[i][j] = 1;
				DFS(cnt, choose + 1);
				lab[i][j] = 0;
			}
		}
}
int main() {
	N = fRI(); M = fRI();
	for (short i = 0; i < N; ++i)
		for (short j = 0; j < M; ++j) {
			lab[i][j] = fRI();
			if (!lab[i][j]) ++m_size;
		}
	DFS(0, 0);
	printf("%d", ans);
}
