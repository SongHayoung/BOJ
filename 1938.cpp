#include<stdio.h>
#include <queue>
using namespace std;
struct tree {
	int x;
	int y;
	int dir;
	int cost;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main(int argc, char** argv){
	int N;
	char buf[50][51];
	int v[50][50][2] = { 0, };
	queue<tree> q;
	tree dst;
	scanf("%d" ,&N);
	for (int i = 0; i < N; ++i)
		scanf("%s", buf[i]);
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (buf[i][j] == 'B') {
				if (buf[i][j + 1] == 'B') {
					v[i][j + 1][0] = 1;
					tree t;
					t.x = j + 1;
					t.y = i;
					t.cost = 0;
					t.dir = 0;
					buf[i][j] = buf[i][j + 1] = buf[i][j + 2] = '0';
					q.push(t);
				}
				else {
					v[i+1][j][1] = 1;
					tree t;
					t.x = j;
					t.y = i+1;
					t.cost = 0;	
					t.dir = 1;
					buf[i][j] = buf[i + 1][j] = buf[i + 2][j] = '0';
					q.push(t);
				}
			}
			else if (buf[i][j] == 'E') {
				if (buf[i][j + 1] == 'E') {
					dst.y = i;
					dst.x = j + 1;
					dst.dir = 0;
					dst.cost = 0;
					buf[i][j] = buf[i][j + 1] = buf[i][j + 2] = '0';
				}
				else {
					dst.y = i+1;
					dst.x = j;
					dst.dir = 1;
					dst.cost = 0;
					buf[i][j] = buf[i + 1][j] = buf[i + 2][j] = '0';
				}
			}
		}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		int dir = q.front().dir;
		q.pop();
		if (y == dst.y&&x == dst.x&&dir == dst.dir) {
			printf("%d", cost);
			return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (dir) {
				if (0 <= nx && nx < N && 0 <= ny - 1 && ny + 1 < N) {
					if (buf[ny - 1][nx] != '1' && buf[ny][nx] != '1' && buf[ny + 1][nx] != '1' && !v[ny][nx][dir]) {
						v[ny][nx][dir] = 1;
						tree t;
						t.x = nx;
						t.y = ny;
						t.dir = dir;
						t.cost = cost + 1;
						q.push(t);
					}
				}
			}
			else {
				if (0 <= nx - 1 && nx + 1 < N && 0 <= ny && ny < N) {
					if (buf[ny][nx - 1] != '1' && buf[ny][nx] != '1' && buf[ny][nx + 1] != '1' && !v[ny][nx][dir]) {
						v[ny][nx][dir] = 1;
						tree t;
						t.x = nx;
						t.y = ny;
						t.dir = dir;
						t.cost = cost + 1;
						q.push(t);
					}
				}
			}
		}
		if (0 < x&&x + 1 < N && 0 < y&&y + 1 < N) {
			if (dir) {
				if (buf[y - 1][x - 1] != '1' && buf[y - 1][x + 1] != '1' && buf[y][x - 1] != '1' && buf[y][x + 1] != '1' && buf[y + 1][x - 1] != '1' && buf[y + 1][x + 1] != '1' && !v[y][x][0]) {
					v[y][x][0] = 1;
					tree t;
					t.x = x;
					t.y = y;
					t.dir = 0;
					t.cost = cost + 1;
					q.push(t);
				}
			}
			else {
				if (buf[y - 1][x - 1] != '1' &&buf[y - 1][x] != '1' && buf[y - 1][x + 1] != '1' && buf[y + 1][x - 1] != '1' && buf[y + 1][x] != '1' && buf[y + 1][x + 1] != '1' && !v[y][x][1]) {
					v[y][x][1] = 1;
					tree t;
					t.x = x;
					t.y = y;
					t.dir = 1;
					t.cost = cost + 1;
					q.push(t);
				}
			}
		}
	}
	printf("0");
}
