#include <stdio.h>
#include <queue>
using namespace std;
struct INFO {
	int y;
	int x;
	int wall;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int map[1000][1000];
int visit[1000][1000][2];
int N, M;
void init() {
	char buf[1001];
	for (int i = 0; i < N; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < M; ++j)
			map[i][j] = buf[j] & 0b1111;
	}
}
int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	char buf[1001];
	for (int i = 0; i < N; ++i) {
		scanf("%s", buf);
		for (int j = 0; j < M; ++j)
			map[i][j] = buf[j] & 0b1111;
	}
	INFO info;
	queue<INFO> q;
	info.x = info.y = info.wall = 0;
	q.emplace(info);
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int wall = q.front().wall;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (!map[ny][nx]&&!visit[ny][nx][wall]) {
					visit[ny][nx][wall] = visit[y][x][wall] + 1;
					info.x = nx; info.y = ny; info.wall = wall;
					q.push(info);
				}
				else if (map[ny][nx] && !wall) {
					nx += dx[i];
					ny += dy[i];
					if (0 <= nx && nx < M && 0 <= ny && ny < N && !map[ny][nx] && !visit[ny][nx][1]) {
						visit[ny][nx][1] = visit[y][x][wall]+2;
						info.x = nx; info.y = ny; info.wall = 1;
						q.push(info);
					}
				}
			}
		}
	}
	if(!visit[N-1][M-1][0] && !visit[N-1][M-1][1]) printf("-1");
	else {
		int amax = 987654321, bmax = 987654321;
		if (visit[N - 1][M - 1][0]) amax = visit[N - 1][M - 1][0];
		if (visit[N - 1][M - 1][1]) bmax = visit[N - 1][M - 1][1];
		printf("%d", min(amax, bmax));
	}
	return 0;
}
