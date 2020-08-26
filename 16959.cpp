#include <algorithm>
#include <memory.h>
#include <queue>
#include <iostream>
using namespace std;
int map[11][11];
int v[11][11][3], n, sx, sy, ans;
int kx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int ky[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int bx[4] = {-1, 1, 1, -1};
int by[4] = {-1, -1, 1, 1};
int lx[4] = {0, 1, 0, -1};
int ly[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
struct st {
    int y, x, p, item;
};
void setMin(pair<int, int> p) {
    for(int i = 0; i < 3; ++i)
        if(v[p.first][p.second][i] == -1)
            v[p.first][p.second][i] = 987654321;
    int n1 = v[p.first][p.second][0], n2 =v[p.first][p.second][1], n3=v[p.first][p.second][2];
    v[p.first][p.second][0] = min(n1, min(n2,n3)+1);
    v[p.first][p.second][1] = min(n2, min(n1,n3)+1);
    v[p.first][p.second][2] = min(n3, min(n1,n2)+1);
    ans = min(n1, min(n2,n3));
}
void bfs() {
    q.push(make_pair(sy, sx));
    v[sy][sx][0] = v[sy][sx][1] = v[sy][sx][2] = 0;
    while(map[q.front().first][q.front().second] != n*n) {
        pair<int,int> p = q.front();
        q.pop();
        queue<st> stq;
        stq.push(st{.y = p.first, .x = p.second, .p = v[p.first][p.second][0], .item = 0});
        stq.push(st{.y = p.first, .x = p.second, .p = v[p.first][p.second][1], .item = 1});
        stq.push(st{.y = p.first, .x = p.second, .p = v[p.first][p.second][2], .item = 2});
        int visit[10][10][3];
        memset(visit,-1,sizeof(visit));
        while(!stq.empty()) {
            st s = stq.front();
            stq.pop();
            switch (s.item) {
                case 0: {
                    for(int i = 0; i < 8; ++i) {
                        int ny = s.y + ky[i];
                        int nx = s.x + kx[i];
                        if(0 <= ny && ny < n && 0 <= nx && nx < n) {
                            if(visit[ny][nx][0] == -1 || visit[ny][nx][0] > s.p + 1) {
                                stq.push(st{.y = ny, .x = nx, .p = s.p + 1, .item = 0});
                                visit[ny][nx][0] = s.p + 1;
                            }
                            if(visit[ny][nx][1] == -1 || visit[ny][nx][1] > s.p + 2) {
                                stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 1});
                                visit[ny][nx][1] = s.p + 2;
                            }
                            if(visit[ny][nx][2] == -1 || visit[ny][nx][2] > s.p + 2) {
                                stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 2});
                                visit[ny][nx][2] = s.p + 2;
                            }
                            if(map[ny][nx] == map[p.first][p.second] + 1) {
                                if(q.empty())
                                    q.push(make_pair(ny,nx));
                                if(v[ny][nx][0] == -1 || v[ny][nx][0] > s.p + 1)
                                    v[ny][nx][0] = s.p + 1;
                            }
                        }
                    }
                }
                break;
                case 1: {
                    for(int i = 0; i < 4; ++i) {
                        for(int j = 1; j <= 10; ++j) {
                            int ny = s.y + by[i] * j;
                            int nx = s.x + bx[i] * j;
                            if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                                if(visit[ny][nx][1] == -1 || visit[ny][nx][1] > s.p + 1) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 1, .item = 1});
                                    visit[ny][nx][1] = s.p + 1;
                                }
                                if(visit[ny][nx][0] == -1 || visit[ny][nx][0] > s.p + 2) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 0});
                                    visit[ny][nx][0] = s.p + 2;
                                }
                                if(visit[ny][nx][2] == -1 || visit[ny][nx][2] > s.p + 2) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 2});
                                    visit[ny][nx][2] = s.p + 2;
                                }
                                if(map[ny][nx] == map[p.first][p.second] + 1) {
                                    if(q.empty())
                                        q.push(make_pair(ny,nx));
                                    if(v[ny][nx][1] == -1 || v[ny][nx][1] > s.p + 1)
                                        v[ny][nx][1] = s.p + 1;
                                }
                            }
                        }
                    }
                }
                break;
                case 2: {
                    for(int i = 0; i < 4; ++i) {
                        for(int j = 1; j<= 10; ++j) {
                            int ny = s.y + ly[i] * j;
                            int nx = s.x + lx[i] * j;
                            if (0 <= ny && ny < n && 0 <= nx && nx < n) {
                                if(visit[ny][nx][2] == -1 || visit[ny][nx][2] > s.p + 1) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 1, .item = 2});
                                    visit[ny][nx][2] = s.p + 1;
                                }
                                if(visit[ny][nx][0] == -1 || visit[ny][nx][0] > s.p + 2) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 0});
                                    visit[ny][nx][0] = s.p + 2;
                                }
                                if(visit[ny][nx][1] == -1 || visit[ny][nx][1] > s.p + 2) {
                                    stq.push(st{.y = ny, .x = nx, .p = s.p + 2, .item = 1});
                                    visit[ny][nx][1] = s.p + 2;
                                }
                                if(map[ny][nx] == map[p.first][p.second] + 1) {
                                    if(q.empty())
                                        q.push(make_pair(ny,nx));
                                    if(v[ny][nx][2] == -1 || v[ny][nx][2] > s.p + 1)
                                        v[ny][nx][2] = s.p + 1;
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
        setMin(q.front());
    }
}
int main(void) {
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) {
                sx = j;
                sy = i;
            }
        }
    memset(v, -1, sizeof(v));
    bfs();
    printf("%d",ans);
}
