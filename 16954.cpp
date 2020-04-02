#include <stdio.h>
#include <queue>
using namespace std;
char buf[8][9];
int dx[9] = { -1,0,1,-1,0,1,-1,0,1 };
int dy[9] = { -1,-1,-1,0,0,0,1,1,1 };
int t = 0;
int main() {
	for (int i = 0; i < 8; ++i)
		scanf("%s", buf[i]);
	queue<pair<int, int>> q;
	q.emplace(7, 0);
	while (!q.empty()) {
		int size = q.size();
		int visit[8][8] = { 0, };
		for (int s = 0; s < size; ++s) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			if (buf[y][x] == '#') continue;
			for (int i = 0; i < 9; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && buf[ny][nx] == '.' && !visit[ny][nx]) {
					visit[ny][nx] = 1;
					if (ny<t) {
						printf("1"); return 0;
					}
					q.emplace(ny, nx);
				}
			}
		}
		for (int i = 0; i < 8; ++i)
			if (buf[7][i] == '#') buf[7][i] = '.';
		for (int i = 6; i >= 0; --i) {
			for (int j = 0; j < 8; ++j) {
				if (buf[i][j] == '#') {
					buf[i + 1][j] = '#';
					buf[i][j] = '.';
				}
			}
		}
		++t;
	}
	printf("0");
}
