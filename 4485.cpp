#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
int N, cave[125][125];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
class link {
public:
	int x;
	int y;
	int cost;
	link(int _x, int _y, int _c) : x(_x), y(_y), cost(_c){}
};
bool operator< (link a, link b) {
	return a.cost > b.cost;
}
int solution() {
	priority_queue<link> pq;
	bool v[125][125] = { false, };
	v[0][0] = true;
	pq.emplace(0, 0, cave[0][0]);
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == N - 1 && ny == N - 1) return cost + cave[ny][nx];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && !v[ny][nx]) {
				v[ny][nx] = true;
				pq.emplace(nx, ny, cost + cave[ny][nx]);
			}
		}
	}
	return -1;
}
int main(void) {
	int p = 0;
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &cave[i][j]);
		printf("Problem %d: %d\n", ++p,solution());
	}
	
	return 0;
}
