#include <stdio.h>
#include <queue>
using namespace std;
int map[1000][1000];
int N, M, K, y, x;
int dir[4], dpos;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; ++i) {
		scanf("%d %d", &y, &x);
		map[y][x] = 1;
	}
	scanf("%d %d", &y, &x);
	map[y][x] = 1;
	for (int i = 0; i < 4; ++i)
		scanf("%d", &dir[i]), --dir[i];
	int flag = 0;
	while (flag < 4) {
		flag = 0;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[dir[dpos]];
			int ny = y + dy[dir[dpos]];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !map[ny][nx]) {
				map[ny][nx] = 1;
				x = nx, y = ny;
				break;
			}
			else {
				dpos = (dpos + 1) % 4;
				++flag;
			}
		}
	}
	printf("%d %d", y, x);

}
