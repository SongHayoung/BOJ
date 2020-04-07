#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
int island = 2, N, ans = 987654321;
int map[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool visit[100][100];
void BFS(int _y, int _x) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	visit[_y][_x] = true;
	int _island = map[_y][_x];
	q.emplace(_y, _x);
	for (int i = 0; i < ans&&!q.empty(); ++i) {
		int size = q.size();
		for (int j = 0; j < size; ++j) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[ny][nx] && map[ny][nx] != _island) {
					if (map[ny][nx]) {
						ans = ans > i ? i : ans;
						return;
					}
					visit[ny][nx] = true;
					q.emplace(ny, nx);
				}
			}
		}
	}
}
int main() {
	bool visit[100][100] = { false, };
	queue<pair<int, int>> q;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &map[i][j]);
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 1 && !visit[i][j]) {
				q.emplace(i, j);
				visit[i][j] = true;
				map[i][j] = island;
				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < N && !visit[ny][nx] && map[ny][nx]) {
							visit[ny][nx] = true;
							q.emplace(ny, nx);
							map[ny][nx] = island;
						}
					}
				}
				++island;
			}
		}
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (!map[i][j]) continue;
			BFS(i, j);
		}
	printf("%d", ans);
}
