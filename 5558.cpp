#include <stdio.h>
#include <queue>
using namespace std;
char cheese[1000][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int sy, sx;
int time, target = 1;
int N, M, H;
void BFS() {
	queue<pair<int, int>> q;
	bool visit[1000][1000] = { false, };
	q.emplace(sy, sx);
	visit[sy][sx] = true;
	while (++time) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (0 <= nx && nx < M && 0 <= ny && ny < N && !visit[ny][nx]) {
					if (cheese[ny][nx] != 'X') {
						q.emplace(ny, nx);
						visit[ny][nx] = true;
					}
					if (cheese[ny][nx] == (target|0b110000)) {
						sy = ny, sx = nx;
						++target;
						return;
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < N; ++i) {
		scanf("%s", cheese[i]);
		for (int j = 0; j < M; ++j)
			if (cheese[i][j] == 'S') sy = i, sx = j;
	}
	while (target<=H) BFS();
	printf("%d", time);
}
