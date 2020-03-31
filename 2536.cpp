#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
struct Line {
	int s, e, n;
};
struct Bus {
	int x1, x2, y1, y2, num;
};
int N, M, K;
int sx, sy, dx, dy;
vector<vector<Line>> VE(100001, vector<Line>());
vector<vector<Line>> HO(100001, vector<Line>());
queue<int> q;
int visit[5001];
Bus b[5001];
void init() {
	int num, x1, x2, y1, y2;
	for (int i = 0; i < K; ++i) {
		scanf("%d %d %d %d %d", &num, &x1, &y1, &x2, &y2);
		if (x1 > x2) x1 ^= x2 ^= x1 ^= x2;
		else if (y1 > y2) y1 ^=y2 ^= y1 ^= y2;
		if (y1 == y2) HO[y1].push_back({ x1,x2,num });
		else VE[x1].push_back({ y1,y2,num });
		b[num].num = num, b[num].x1 = x1, b[num].x2 = x2, b[num].y1 = y1, b[num].y2 = y2;
	}
}
int main(void) {
	scanf("%d %d", &M, &N);
	scanf("%d", &K);
	init();
	scanf("%d %d %d %d", &sx, &sy, &dx, &dy);
	for (int i = 0; i < HO[sy].size(); ++i) {
		if (HO[sy][i].s <= sx && sx <= HO[sy][i].e) {
			visit[HO[sy][i].n] = 1;
			q.push(HO[sy][i].n);
		}
	}
	for (int i = 0; i < VE[sx].size(); ++i) {
		if (VE[sx][i].s <= sy && sy <= VE[sx][i].e) {
			visit[VE[sx][i].n] = 1;
			q.push(VE[sx][i].n);
		}
	}
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if (b[c].x1 <= dx && dx <= b[c].x2 && b[c].y1 <= dy && dy <= b[c].y2) {
			printf("%d", visit[c]); return 0;
		}
		if (b[c].x1 == b[c].x2) {
			for (int i = b[c].y1; i <= b[c].y2; ++i) {
				for (int j = 0; j < HO[i].size(); ++j) {
					if (!visit[HO[i][j].n] && HO[i][j].s <= b[c].x1 && b[c].x1 <= HO[i][j].e) {
						visit[HO[i][j].n] = visit[b[c].num] + 1;
						q.push(HO[i][j].n);
					}
				}
			}
			for (int i = 0; i < VE[b[c].x1].size(); ++i) {
				if (!visit[VE[b[c].x1][i].n]) {
					if (VE[b[c].x1][i].s <= b[c].y1 && b[c].y1 <= VE[b[c].x1][i].e) {
						visit[VE[b[c].x1][i].n] = visit[b[c].num] + 1;
						q.push(VE[b[c].x1][i].n);
					}
					else if(VE[b[c].x1][i].s <= b[c].y2 && b[c].y2 <= VE[b[c].x1][i].e) {
						visit[VE[b[c].x1][i].n] = visit[b[c].num] + 1;
						q.push(VE[b[c].x1][i].n);
					}
				}
			}
		}
		else {
			for (int i = b[c].x1; i <= b[c].x2; ++i) {
				for (int j = 0; j < VE[i].size(); ++j) {
					if (!visit[VE[i][j].n] && VE[i][j].s <= b[c].y1 && b[c].y1 <= VE[i][j].e) {
						visit[VE[i][j].n] = visit[b[c].num] + 1;
						q.push(VE[i][j].n);
					}
				}
			}
			for (int i = 0; i < HO[b[c].y1].size(); ++i) {
				if (!visit[HO[b[c].y1][i].n]) {
					if (HO[b[c].y1][i].s <= b[c].x1 && b[c].x1 <= HO[b[c].y1][i].e) {
						visit[HO[b[c].y1][i].n] = visit[b[c].num] + 1;
						q.push(HO[b[c].y1][i].n);
					}
					else if (HO[b[c].y1][i].s <= b[c].x2 && b[c].x2 <= HO[b[c].y1][i].e) {
						visit[HO[b[c].y1][i].n] = visit[b[c].num] + 1;
						q.push(HO[b[c].y1][i].n);
					}
				}
			}
		}
	}
}
