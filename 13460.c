#include <stdio.h>
char m[12][12];
int cmd[10];
int R[2], B[2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int answer = 100;
void simulation() {
	int rx = R[1], ry = R[0], bx = B[1], by = B[0];
	int nrx, nry, nbx, nby, bf = 0, rf = 0;
	for (int i = 0; i < 10 && i+1 < answer; i++) {
		while (1) {
			nrx = rx + dx[cmd[i]];
			nry = ry + dy[cmd[i]];
			if (m[nry][nrx] != '#'&&!(nrx == bx && nry == by)) {
				rx = nrx;
				ry = nry;
			}
			else break;
			if (m[ry][rx] == 'O') {
				ry = ry = 99;
				rf++;
				break;
			}
		}
		while (1) {
			nbx = bx + dx[cmd[i]];
			nby = by + dy[cmd[i]];
			if (m[nby][nbx] != '#'&&!(nbx == rx && nby == ry)) {
				bx = nbx;
				by = nby;
			}
			else break;
			if (m[by][bx] == 'O') {
				by = bx = 99;
				bf++;
				break;
			}
		}
		if (!rf) {
			while (1) {
				nrx = rx + dx[cmd[i]];
				nry = ry + dy[cmd[i]];
				if (m[nry][nrx] != '#'&&!(nrx == bx && nry == by)) {
					rx = nrx;
					ry = nry;
				}
				else break;
				if (m[ry][rx] == 'O') {
					rf++;
					break;
				}
			}
		}
		if (!bf) {
			while (1) {
				nbx = bx + dx[cmd[i]];
				nby = by + dy[cmd[i]];
				if (m[nby][nbx] != '#'&&!(nbx == rx && nby == ry)) {
					bx = nbx;
					by = nby;
				}
				else break;
				if (m[by][bx] == 'O') {
					bf++;
					break;
				}
			}
		}
		if (bf) break;
		if (rf) { answer = answer > i + 1 ? i + 1 : answer; break; }
	}
}
void DFS(int c) {
	if (c == 10) {
		simulation();
		return;
	}
	for (int i = 0; i < 4; i++) {
		cmd[c] = i;
		DFS(c + 1);
	}
}
int main(int argc, char** argv) {
	int N, M;
	char c;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", m[i]);
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 'R') { R[0] = i; R[1] = j; m[i][j] = '.'; }
			if (m[i][j] == 'B') { B[0] = i; B[1] = j; m[i][j] = '.'; }
		}
	}
	DFS(0);
	answer == 100 ? printf("-1") : printf("%d", answer);
}
