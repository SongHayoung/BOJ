#include <stdio.h>
#include <queue>
using namespace std;
short map[52][52];
char buf[51];
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void BFS(int _y, int _x, int cost) {
    queue<pair<int, int>> q;
    int visit[52][52] = {0,};
    visit[_y][_x] = 1;
    map[_y][_x] = cost;
    q.emplace(_y, _x);
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<=M+1 && 0<=ny&&ny<=N+1 && !visit[ny][nx] && map[ny][nx]<cost){
                visit[ny][nx] = map[ny][nx] = cost;
                q.emplace(ny,nx);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", buf);
        for (int j = 1; j <= M; ++j)
            map[i][j] = buf[j - 1] & 0b1111;
    }
    int ans = 0;
    for (int r = 1; r <= 9; ++r) {
        BFS(0, 0, r);
        for(int i = 1; i <=N+1; ++i)
            for(int j = 1; j <= M+1; ++j)
                if(map[i][j]<r) ++ans,++map[i][j];
    }
    printf("%d", ans);
}
