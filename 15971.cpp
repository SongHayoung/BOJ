#include <stdio.h>
#include <queue>
using namespace std;
struct INFO {
	int pos;
	int dist;
	int max;
};
int N, src, dst, f, e, c;
vector<pair<int, int>> v[100001];
bool visit[100001];
int BFS() {
	if (src == dst) return 0;
	queue<INFO> q;
	visit[src] = true;
	q.push({ src, 0, 0 });
	while (!q.empty()) {
		INFO info = q.front();
		q.pop();
		for (auto s : v[info.pos]) {
			if (visit[s.first]) continue;
			if (s.first == dst)
				return info.max > s.second ? info.dist + s.second - info.max : info.dist;
			visit[s.first] = true;
			q.push({ s.first,info.dist + s.second,s.second > info.max ? s.second : info.max });
		}
	}
}
int main() {
	scanf("%d %d %d", &N, &src, &dst);
	for (int i = 0; i < N - 1; ++i) {
		scanf("%d %d %d", &f, &e, &c);
		v[f].emplace_back(e, c);
		v[e].emplace_back(f, c);
	}
	printf("%d", BFS());
}
