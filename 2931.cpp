#include<stdio.h>
#include <queue>
using namespace std;
struct gas {
	int x;
	int y;
};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main(int argc, char** argv){
	int N, M, nx, ny, ansx, ansy;
	char buf[25][26], ansc;
	int v[25][25] = { 0, };
	queue<gas> q;
	pair<int, int> mos;
	scanf("%d %d" ,&N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", buf[i]);
		for (int j = 0; j < M; ++j)
			if (buf[i][j] == 'M') mos.first = i, mos.second = j;
	}
	for (int i = 0; i < 4; ++i) {
		nx = mos.second + dx[i];
		ny = mos.first + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (buf[ny][nx] == '.') continue;
		switch (i){
		case 0:
			if (buf[ny][nx] == '+' || buf[ny][nx] == '|' || buf[ny][nx] == '1' || buf[ny][nx] == '4') {
				gas g;
				g.x = nx;
				g.y = ny;
				v[ny][nx] = 1;
				q.push(g);
			}
			break;
		case 1:
			if (buf[ny][nx] == '+' || buf[ny][nx] == '-' || buf[ny][nx] == '3' || buf[ny][nx] == '4') {
				gas g;
				g.x = nx;
				g.y = ny;
				v[ny][nx] = 1;
				q.push(g);
			}
			break;
		case 2:
			if (buf[ny][nx] == '+' || buf[ny][nx] == '|' || buf[ny][nx] == '2' || buf[ny][nx] == '3') {
				gas g;
				g.x = nx;
				g.y = ny;
				v[ny][nx] = 1;
				q.push(g);
			}
			break;
		case 3:
			if (buf[ny][nx] == '+' || buf[ny][nx] == '-' || buf[ny][nx] == '2' || buf[ny][nx] == '1') {
				gas g;
				g.x = nx;
				g.y = ny;
				v[ny][nx] = 1;
				q.push(g);
			}
			break;
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			if (buf[y][x] == '|' && (i == 1 || i == 3)) continue;
			if (buf[y][x] == '|' && (i == 1 || i == 3)) continue;
			if (buf[y][x] == '-' && (i == 0 || i == 2)) continue;
			if (buf[y][x] == '1' && (i == 0 || i == 3)) continue;
			if (buf[y][x] == '2' && (i == 2 || i == 3)) continue;
			if (buf[y][x] == '3' && (i == 1 || i == 2)) continue;
			if (buf[y][x] == '4' && (i == 0 || i == 1)) continue;
			nx = x + dx[i];
			ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && !v[ny][nx]) {
				v[ny][nx] = 1;
				if (buf[ny][nx] != '.' && buf[ny][nx] != 'M' && buf[ny][nx] !='Z') {
					gas g;
					g.x = nx;
					g.y = ny;
					q.push(g);
				}
				else if(buf[ny][nx] == '.'){
					ansx = nx; ansy = ny;
					printf("%d %d ", ansy + 1, ansx + 1);
					int conn[4] = { 0, };
					for (int j = 0; j < 4; ++j) {
						nx = ansx + dx[j];
						ny = ansy + dy[j];
						if (0 <= nx && nx < M && 0 <= ny && ny < N) {
							if (buf[ny][nx] == '.') continue;
							if (j == 0 && (buf[ny][nx] == '+' || buf[ny][nx] == '|' || buf[ny][nx] == '1' || buf[ny][nx] == '4')) conn[j] = 1;
							if (j == 1 && (buf[ny][nx] == '+' || buf[ny][nx] == '-' || buf[ny][nx] == '3' || buf[ny][nx] == '4')) conn[j] = 1;
							if (j == 2 && (buf[ny][nx] == '+' || buf[ny][nx] == '|' || buf[ny][nx] == '2' || buf[ny][nx] == '3')) conn[j] = 1;
							if (j == 3 && (buf[ny][nx] == '+' || buf[ny][nx] == '-' || buf[ny][nx] == '1' || buf[ny][nx] == '2')) conn[j] = 1;
						}
					}
					if (conn[0] && conn[1] && conn[2] && conn[3]) {
						printf("+");
						return 0;
					}
					if (conn[0]) {
						if (conn[1]) printf("2");
						if (conn[2]) printf("|");
						if (conn[3]) printf("3");
						return 0;
					}
					if (conn[1]) {
						if (conn[2]) printf("1");
						if (conn[3]) printf("-");
						return 0;
					}
					if (conn[2]) printf("4");
					return 0;
				}
			}
		}
	}
}
