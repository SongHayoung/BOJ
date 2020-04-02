#include <stdio.h>
#include <queue>
using namespace std;
char buf[1000][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int M, N;
void simulation() {
	int x, y, time = 1;
	queue<pair<int, int>> fire;
	queue<pair<int, int>> p;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (buf[i][j] == 'F') fire.emplace(i, j);
			else if (buf[i][j] == 'J') p.emplace(i, j), x = j, y = i;
			if (!x || !y || x == M - 1 || y == N - 1) { printf("1\n"); return; }
			while (!p.empty()) {
				int fsize = fire.size();
				for (int i = 0; i < fsize; ++i) {
					x = fire.front().second;
					y = fire.front().first;
					fire.pop();
					for (int j = 0; j < 4; ++j) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						if (0 <= nx && nx < M && 0 <= ny && ny < N) {
							if (buf[ny][nx] == '.' || buf[ny][nx] == 'J') buf[ny][nx] = 'F', fire.emplace(ny, nx);
						}
					}
				}
				int psize = p.size();
				for (int i = 0; i < psize; ++i) {
					x = p.front().second;
					y = p.front().first;
					p.pop();
					for (int j = 0; j < 4; ++j) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						if (0 <= nx && nx < M && 0 <= ny && ny < N) {
							if (buf[ny][nx] == '.') {
								buf[ny][nx] = 'J', p.emplace(ny, nx);
								if (!nx || !ny || nx == M - 1 || ny == N - 1) { printf("%d\n", time + 1); return; }
							}
						}
					}
				}
				++time;
			}
			printf("IMPOSSIBLE\n");
			return;
}
int main(void) {
	scanf("%d %d\n", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%s", buf[i]);
	simulation();
}
