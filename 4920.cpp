#include <stdio.h>
#include <vector>
using namespace std;
int map[100][100];
int N;
vector<vector<vector<int>>> b = {{{1,1,1,1}},{{1},{1},{1},{1}},
								 {{1,1,0},{0,1,1}},{{0,1},{1,1},{1,0}},
								 {{1,1},{1,1}},
								 {{1,1,1},{0,0,1}},{{1,0,0,},{1,1,1}},{{0,1},{0,1},{1,1}},{{1,1},{1,0},{1,0}},
								 {{1,1,1},{0,1,0}},{{1,0},{1,1},{1,0}},{{0,1,0},{1,1,1}},{{0,1},{1,1},{0,1}}};
int main() {
	scanf("%d", &N);
	int ans, tc = 0;
	while (N) {
		ans = -4000001;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				scanf("%d", &map[i][j]);
		for (int rep = 0; rep < 13; ++rep) {
			for (int i = 0; i <= N - b[rep].size(); ++i)
				for (int j = 0; j <= N - b[rep][0].size(); ++j) {
					int cur = 0;
					for (int by = 0; by < b[rep].size(); ++by)
						for (int bx = 0; bx < b[rep][0].size(); ++bx) {
							if (b[rep][by][bx]) {
								cur += map[i + by][j + bx];
							}
						}
					ans = ans > cur ? ans : cur;
				}
		}
		printf("%d. %d\n", ++tc, ans);
		scanf("%d", &N);
	}
}
