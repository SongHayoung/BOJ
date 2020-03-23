#include <stdio.h>
#include <queue>
using namespace std;
#define FLOWER 987654321
struct grounds {
	int x;
	int y;
	int color;
};
int map[50][50], G, R, N, M, ans, i, j, SZ, ny, nx, y, x;
struct grounds gr[10], g;
int g_idx = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void simulation() {
	queue<grounds> gq;
	queue<grounds> rq;
	int status[50][50] = { 0, }, time = 2, flower = 0;
	for (i = 0; i < g_idx; ++i) {
		if (!gr[i].color) continue;
		if (gr[i].color == 1)
			gq.push(gr[i]);
		else if(gr[i].color == -1)
			rq.push(gr[i]);
		status[gr[i].y][gr[i].x] = gr[i].color;
	}
	while (!gq.empty() && !rq.empty()) {
		SZ = gq.size();
		for (i = 0; i < SZ; ++i) {
			x = gq.front().x;
			y = gq.front().y;
			gq.pop();
			if (status[y][x] == FLOWER) continue;
			for (j = 0; j < 4; ++j) {
				nx = x + dx[j];
				ny = y + dy[j];
				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					if (!status[ny][nx] && map[ny][nx]) {
						status[ny][nx] = time;
						g.x = nx;
						g.y = ny;
						gq.push(g);
					}
				}
			}
		}
		SZ = rq.size();
		for (i = 0; i < SZ; ++i) {
			x = rq.front().x;
			y = rq.front().y;
			rq.pop();
			if (status[y][x] == FLOWER) continue;
			for (j = 0; j < 4; ++j) {
				nx = x + dx[j];
				ny = y + dy[j];
				if (0 <= nx && nx < M && 0 <= ny && ny < N) {
					if (!status[ny][nx] && map[ny][nx]) {
						status[ny][nx] = -time;
						g.x = nx;
						g.y = ny;
						rq.push(g);
					}
					else if (status[ny][nx] == time && map[ny][nx]) {
						status[ny][nx] = FLOWER;
						++flower;
					}
				}
			}
		}
		++time;
	}
	ans = ans > flower ? ans : flower;
}
void DFS(int c,int g, int r) {
	if (c == g_idx) {
		if(g==G&&r==R)
			simulation();
		return;
	}
	if (g < G) {
		gr[c].color = 1;
		DFS(c + 1, g + 1, r);
		gr[c].color = 0;
	}
	if (r < R) {
		gr[c].color = -1;
		DFS(c + 1, g, r + 1);
		gr[c].color = 0;
	}
	if (G + R < g_idx) {
		gr[c].color = 0;
		DFS(c + 1, g, r);
	}
}
int main() {
	scanf("%d %d %d %d", &N, &M, &G, &R);
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				gr[g_idx].y = i;
				gr[g_idx].x = j;
				++g_idx;
			}
		}
	DFS(0, 0, 0);
	printf("%d", ans);
}
