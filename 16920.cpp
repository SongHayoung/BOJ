#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int>> q[10];
int n, m, p;
int s[10];
char map[1000][1001];
int ans[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct st {
    int y, x, cur, mv;
};
queue<st> stq;
void bfs() {
    while(!stq.empty()) {
        st t = stq.front();
        stq.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            if(0<=ny&&ny<n && 0<=nx&&nx<m && map[ny][nx] == '.' && t.mv) {
                map[ny][nx] = (t.cur+1)|0b110000;
                ++ans[t.cur];
                if(t.mv > 1)
                    stq.push(st{.y = ny, .x = nx, .cur = t.cur, .mv = t.mv-1});
                else
                    q[t.cur].push(make_pair(ny, nx));
            }
        }
    }
}
int main(void) {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 0; i < p; ++i)
        scanf("%d", &s[i]);
    for (int i = 0; i < n; ++i) {
        scanf("%s", map[i]);
        for (int j = 0; j < m; ++j) {
            if ('1' <= map[i][j] && map[i][j] <= '9') {
                q[(map[i][j] & 0b1111) - 1].push(make_pair(i, j));
                ++ans[(map[i][j] & 0b1111) - 1];
            }
        }
    }
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < p; ++i) {
            if (q[i].empty()) continue;
            flag = true;
            int size = q[i].size();
            for (int j = 0; j < size; ++j) {
                pair<int, int> pr = q[i].front();
                q[i].pop();
                stq.push(st{.y = pr.first, .x = pr.second, .cur = i, .mv = s[i]});
            }
            bfs();
        }
    }
    for(int i = 0; i < p; ++i)
        printf("%d ", ans[i]);
}
