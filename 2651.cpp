#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct car {
	long time;
	long dist;
	vector<short> visit;
};
bool operator<(car a, car b) {
	return a.time > b.time;
}
long len = 0;
int N, m;
long arr[102];
int t[100];
int s;
short visit[100][100];
int main() {
	scanf("%d", &m);
	scanf("%d", &s);
	for (int i = 1; i <= s+1; ++i) {
		scanf("%d", &len);
		arr[i] = arr[i - 1] + len;
	}
	for (int i = 1; i <= s; ++i)	scanf("%d", &t[i]);
	priority_queue<car> q;
	car c;
	long long maxt = 1 << 29;
	vector<int> ans;
	q.push({ 0,0,{0} });
	while (!q.empty()) {
		c = q.top();
		q.pop();
		if (c.dist < arr[s + 1]) {
			for (int i = c.visit.back() + 1; i <= s + 1; ++i) {
				if (arr[i] <= c.dist + m && !visit[c.visit.back()][i]) {
					visit[c.visit.back()][i] = 1;
					vector<short> v = c.visit;
					v.push_back(i);
					q.push({ c.time + t[i],arr[i],v });
				}
				else
					break;
			}
		}
		else {
			printf("%d\n", c.time);
			printf("%d\n", c.visit.size() - 2);
			for (int i = 1; i < c.visit.size() - 1; ++i) {
				printf("%d ", c.visit[i]);
			}
			return 0;
		}
	}
}
