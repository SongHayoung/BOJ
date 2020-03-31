#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
struct INFO {
	int y,x, prev,c,d;
};
char buf[50][51];
int visit[50][50][4][2][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int M, N, x, y, c,d, dir;
int main(void) {
	scanf("%d %d\n", &N, &M);
	queue<INFO> q;
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		scanf("%s", buf[i]);
		for (int j = 0; j < M; ++j) {
			if (buf[i][j] == 'S') x = j, y = i;
			if (buf[i][j] == 'C' && !flag) buf[i][j] = 'D', flag = true;
		}
	}
	visit[y][x][0][0][0] = visit[y][x][1][0][0] = visit[y][x][2][0][0] = visit[y][x][3][0][0] = 1;
	q.push({ y,x,0,0,0 });
	q.push({ y,x,1,0,0 });
	q.push({ y,x,2,0,0 });
	q.push({ y,x,3,0,0 });
	int ans = 0;
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		dir = q.front().prev;
		c = q.front().c;
		d = q.front().d;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (i == dir) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !visit[ny][nx][i][c][d] && buf[ny][nx]!='#') {
				int nc = c, nd = d;
				switch (buf[ny][nx]) {
				case '.': break;
				case 'C': nc = 1; break;
				case 'D': nd = 1; break;
				}
				visit[ny][nx][i][nc][nd] = visit[y][x][dir][c][d] + 1;
				if (nc&&nd) {
					printf("%d", visit[ny][nx][i][nc][nd]-1); return 0;
				}
				else q.push({ ny,nx,i,nc,nd });
			}
		}
	}
	printf("-1");
}
