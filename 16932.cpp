#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int map[1000][1000];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int sz[500*500 + 2];
int island = 2, n, m, ans = 0;
int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &map[i][j]);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 1) {
                int cnt = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                map[i][j] = island;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = p.second + dx[k];
                        int ny = p.first + dy[k];
                        if (0 <= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] == 1) {
                            map[ny][nx] = island;
                            ++cnt;
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
                sz[island++] = cnt;
            }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!map[i][j]) {
                int cmp = 1;
                int visit[4] = {-1, -1, -1, -1};
                for (int k = 0; k < 4; ++k) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                        bool flag = true;
                        for (int l = 0; l < k; ++l)
                            if (map[ny][nx] == visit[l])
                                flag = false;
                        if (flag) {
                            cmp += sz[map[ny][nx]];
                            visit[k] = map[ny][nx];
                        }
                    }
                }
                ans = max(ans, cmp);
            }
    printf("%d", ans);
}
