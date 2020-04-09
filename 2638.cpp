#include <stdio.h>
#include <queue>
using namespace std;
int cheese[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;
int c;
void BFS() {
	queue<pair<int, int>> q;
	int visit[100][100] = { false, };
	q.emplace(0, 0);
	visit[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) {
				if (!cheese[ny][nx] && !visit[ny][nx]) q.emplace(ny, nx);
				++visit[ny][nx];
			}
		}
	}
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			if (cheese[i][j] && visit[i][j]>=2) cheese[i][j]^=1,--c;
}
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			scanf("%d", &cheese[i][j]);
			if (cheese[i][j]) ++c;
		}
	int time = 0;
	while (c) {
		BFS();
		++time;
	}
	printf("%d", time);
}
