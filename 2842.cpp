#include <stdio.h>
#include <stdlib.h>
char map[50][51];
int dist[50][50];
int ans = 987654321;
int homes = 0, N;
int pPos[2];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int kPos[100][2], kidx = 0;
int arr[2500];
int BFS(int _y, int _x, int min, int max) {
	if (dist[_y][_x]<min || dist[_y][_x]>max) return 0;
	for (int i = 0; i < kidx; ++i)
		if (dist[kPos[i][0]][kPos[i][1]]<min || dist[kPos[i][0]][kPos[i][1]]>max) return 0;

	int visit[50][50] = { 0, };
	visit[_y][_x] = 1;
	register int ret = 0, s = 0, e = 1, x, y, nx, ny, i;
	int q[2300][2];
	q[s][0] = _y; q[s][1] = _x;
	while (s != e) {
		x = q[s][1];
		y = q[s][0];
		++s;
		for (i = 0; i < 8; ++i) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[ny][nx] && min <= dist[ny][nx] && dist[ny][nx] <= max) {
				visit[ny][nx] = 1;
				if (map[ny][nx] == 'K') ++ret;
				q[e][0] = ny; q[e][1] = nx;
				++e;
			}
		}
	}
	return ret;
}
int compare(const void *A, const void *B) {
	return *(int*)A > *(int*)B ? 1 : -1;
}
int main(void) {
	scanf("%d", &N);
	int idx = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%s", map[i]);
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 'K') {
				++homes;
				if (kidx < 100) {
					kPos[kidx][0] = i;
					kPos[kidx++][1] = j;
				}
			}
			else if (map[i][j] == 'P') pPos[0] = i, pPos[1] = j;
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			scanf("%d", &dist[i][j]);
			arr[idx++] = dist[i][j];
		}
	qsort(arr, idx, sizeof(int), compare);
	int s = 0, e = 0;
	while (e<idx) {
		while (1) {
			if (BFS(pPos[0], pPos[1], arr[s], arr[e]) != homes) break;
			ans = ans > arr[e] - arr[s] ? arr[e] - arr[s] : ans;
			while (s + 1 < idx && arr[s] == arr[s + 1])	++s;
			++s;
		}
		while (e + 1 < idx&&arr[e] == arr[e + 1]) ++e;
		++e;
	}
	printf("%d", ans);
	return 0;
}
