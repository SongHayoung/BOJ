#include <stdio.h>
#include <stdlib.h>
int map[10][10][2];
int b[10][10]; 
int N, wans = 0, bans = 0;
int MAXb = 0, MAXw = 0;
int dx[4] = { -1,1,-1,1 };
int dy[4] = { -1,-1,1,1 };
void DFS(int put, int px, int py, int worb) {
	for (int i = py; i < N; ++i) {
		for (int j = i == py ? px + 2 : worb ? i & 1 ? 0 : 1 : i & 1 ? 1 : 0; j < N; j += 2) {
			if (!worb && put + MAXw - map[i][j][1] < wans) return;
			if (worb && put + MAXb - map[i][j][1] < bans) return;
			if (map[i][j][0] && !b[i][j]) {
				int flag = 1;
				for (int k = 0; k < 4 && flag; ++k) {
					int x = j, y = i;
					while (0 <= x && x < N && 0 <= y && y < N && flag) {
						if (b[y][x] == -1) flag = 0;
						y += dy[k];
						x += dx[k];
					}
				}
				if (flag) {
					for (int k = 0; k < 4 && flag; ++k) {
						int x = j + dx[k], y = i + dy[k];
						while (0 <= x && x < N && 0 <= y && y < N) {
							++b[y][x];
							y += dy[k];
							x += dx[k];
						}
					}
					b[i][j] = -1;
					DFS(put + 1, j, i, worb);
					b[i][j] = 0;
					for (int k = 0; k < 4 && flag; ++k) {
						int x = j + dx[k], y = i + dy[k];
						while (0 <= x && x < N && 0 <= y && y < N) {
							--b[y][x];
							y += dy[k];
							x += dx[k];
						}
					}
				}
			}
		}
	}
	worb ? bans > put ? (bans = bans) : (bans = put) : wans > put ? (wans = wans) : (wans = put);
	return;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j][0]);
			if (i & 1) {
				if (j & 1) {
					if (map[i][j][0]) ++MAXw;
					map[i][j][1] = MAXw;
				}
				else {
					if (map[i][j][0]) ++MAXb;
					map[i][j][1] = MAXb;
				}
			}
			else {
				if (j & 1) {
					if (map[i][j][0]) ++MAXb;
					map[i][j][1] = MAXb;
				}
				else {
					if (map[i][j][0]) ++MAXw;
					map[i][j][1] = MAXw;
				}
			}
		}
	DFS(0, -2, 0, 0);
	DFS(0, -1, 0, 1);
	printf("%d", bans + wans);
}
