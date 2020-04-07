#include<stdio.h>
int ans;
int N, M;
int need;
char buf[30][31];
bool visit[30][30];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
void DFS(int _y, int _x, int depth, int visited) {
	if (visited == need) {
		ans = ans > depth ? depth : ans; return;
	}
	if (depth >= ans) return;
	for (int i = 0; i < 4; ++i) {
		int nvisited = 0;
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		while (1) {
			if (visit[ny][nx]||0>nx||0>ny||N<=ny||M<=nx||buf[ny][nx]=='*') break;
			visit[ny][nx] = true;
			ny += dy[i]; nx += dx[i];
			++nvisited;
		}
		nx = nx - dx[i];
		ny = ny - dy[i];
		if (visited + nvisited == need) ans = ans > depth + 1 ? depth + 1 : ans;
		else {if(!(ny==_y&&nx==_x))DFS(ny, nx, depth + 1, visited + nvisited);}
		while (1) {
			if (ny == _y && nx == _x) break;
			visit[ny][nx] = false;
			ny -= dy[i]; nx -= dx[i];
		}
		visit[ny][nx] = true;
	}
}
int main() {
	int tc = 0;
	while (scanf("%d", &N)!=EOF) {
		scanf("%d", &M);
		need = 0; ans = 987654321;
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf[i]);
			for (int j = 0; j < M; ++j)
				if (buf[i][j] == '.') ++need;
		}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (buf[i][j] == '.') {
					visit[i][j] = true;
					DFS(i, j, 0, 1);
					visit[i][j] = false;
				}
		printf("Case %d: ", ++tc);
		ans == 987654321 ? printf("-1\n") : printf("%d\n", ans);
	}
}
