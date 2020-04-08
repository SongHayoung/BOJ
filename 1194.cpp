#include <stdio.h>
#include <queue>
using namespace std;
struct INFO {
	short y, x, key, cost;
};
char maze[50][51];
int N, M;
short BFS(int &x, int &y) {
	queue<INFO> q;
	bool visit[50][50][64] = { false, };
	short dx[4] = { 0,1,0,-1 };
	short dy[4] = { -1,0,1,0 };
	short c, k, nx, ny, i;
	q.push({ y,x,0,0 });
	visit[y][x][0] = true;
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		k = q.front().key;
		c = q.front().cost;
		q.pop();
		for (i = 0; i < 4; ++i) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !visit[ny][nx][k] && maze[ny][nx] != '#') {
				visit[ny][nx][k] = true;
				if (maze[ny][nx] == '1') return c + 1;
				else if (maze[ny][nx] == '.')q.push({ ny,nx,k,c + 1 });
				else if ('a' <= maze[ny][nx] && maze[ny][nx] <= 'f')q.push({ ny,nx,k | (1 << (maze[ny][nx] - 'a')),c + 1 });
				else if ('A' <= maze[ny][nx] && maze[ny][nx] <= 'F' && (k&(1 << (maze[ny][nx] - 'A'))))	q.push({ ny,nx,k,c + 1 });
			}
		}
	}
	return -1;
}
int main() {
	int x = 0, y = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", maze[i]);
		for (int j = 0; j < M && !x && !y; ++j)
			if (maze[i][j] == '0') x = j, y = i, maze[i][j] = '.';
	}
	printf("%d", BFS(x,y));
}
