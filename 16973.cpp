#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <stdlib.h>
using namespace std;
int n, m, h, w, sy, sx, ey, ex;
int map[1000][1000];
int v[1000][1000];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void changeMap() {
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            if(map[i][j] == 1) {
                int mini = min(i+1, n), minj = min(j+1, m);
                for(int ni = max(i - h + 1, 0); ni <mini; ++ni)
                    for(int nj = max(j - w + 1,0); nj <minj; ++nj) {
                        if(!map[ni][nj])
                            map[ni][nj] = 2;
                    }
            }
        }
}
int main(void) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d",&map[i][j]);
    memset(v, -1, sizeof(v));
    scanf("%d %d %d %d %d %d", &h, &w, &sy, &sx, &ey, &ex);
    --sy; --sx; --ey; --ex;
    changeMap();
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    v[sy][sx] = 0;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = p.second + dx[i];
            int ny = p.first + dy[i];
            if(0<= nx && nx <= m - w && 0 <= ny && ny <= n - h && !map[ny][nx] && v[ny][nx] == -1) {
                v[ny][nx] = v[p.first][p.second] + 1;
                q.push(make_pair(ny, nx));
                if(ny == ey && nx == ex) {
                    printf("%d",v[ey][ex]);
                    exit(0);
                }
            }
        }
    }
    printf("%d",v[ey][ex]);
}
