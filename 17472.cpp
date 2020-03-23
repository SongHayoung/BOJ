#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAXINT 987654321
using namespace std;
int map[10][10];
int dist[8][8];
int graph[8] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M, island;
class INFO {
public:
	int f;
	int e;
	int d;
};
bool operator< (INFO a, INFO b) {
	return a.d > b.d;
}
int get_value(int c) {
	if (!graph[c]) return 0;
	if (!(graph[c] ^ c)) return c;
	return get_value(graph[c]);
}
void init() {
	island = 2;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (!(map[i][j] ^ 1)) {
				q.emplace(i, j);
				map[i][j] = island;
				while (!q.empty()) {
					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < M && 0 <= ny && ny < N && map[ny][nx] == 1) {
							map[ny][nx] = island;
							q.emplace(ny, nx);
						}
					}
				}
				++island;
			}
		}

	for (int i = 2; i < island; ++i)
		for (int j = 2; j < island; ++j)
			dist[i][j] = MAXINT;
}
void get_dist() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (map[i][j])
				for (int k = 0; k < 4; ++k)
					for (int len = 1; len <= 10; ++len) {
						int nx = j + len * dx[k];
						int ny = i + len * dy[k];
						if (0 > nx || nx >= M || 0 > ny || ny >= N) break;
						if (len <= 2 && map[ny][nx] != 0) break;
						if (map[ny][nx] == map[i][j]) break;
						if (map[ny][nx]) { dist[map[i][j]][map[ny][nx]] = dist[map[ny][nx]][map[i][j]] = min(dist[map[i][j]][map[ny][nx]], len - 1); break; }
					}
}
int solution() {
	int maxisland = island - 1;
	priority_queue<INFO> pq;
	for (int i = 2; i <= maxisland; ++i)
		for (int j = 2; j <= maxisland; ++j) {
			if (dist[i][j] == MAXINT) continue;
			INFO Info;
			Info.f = i;
			Info.e = j;
			Info.d = dist[i][j];
			pq.push(Info);
		}
	if (pq.empty()) return -1;
	int ans = 0;
	while (!pq.empty()) {
		int f = pq.top().f;
		int e = pq.top().e;
		int d = pq.top().d;
		pq.pop();
		int f_val = get_value(graph[f]);
		int e_val = get_value(graph[e]);
		if (f_val == e_val && f_val != 0) continue;
		if (f_val == 0 && e_val != 0) { graph[f] = e_val; ans += d; }
		else if (e_val == 0 && f_val != 0) { graph[e] = f_val; ans += d; }
		else if (f_val == 0 && e_val == 0) { graph[e] = graph[f] = min(f, e); ans += d; }
		else if (f_val != e_val) {
			int min_val = min(f_val, e_val);
			int max_val = max(f_val, e_val);
			graph[max_val] = min_val;
			ans += d;
		}
	}
	int std_val = get_value(graph[2]);
	if (!std_val) return -1;
	for (int i = 3; i <= maxisland; ++i)
		if (get_value(graph[i]) != std_val) return -1;
	return ans;
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%d", &map[i][j]);
	init();
	get_dist();
	printf("%d", solution());
}
