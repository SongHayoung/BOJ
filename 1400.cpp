#include <stdio.h>
#include <queue>
using namespace std;
struct light{
    int dir;
    int time[2];
    int time_left;
};
struct BUS{
    int y;
    int x;
    int cost;
};
char buf[20][21];
int N, M, lights;
int sx, sy;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
light l[10];
void BFS(){
    queue<BUS> q;
    int visit[20][20] = {0,};
    visit[sy][sx] = 1;
    q.push({sy,sx,0});
    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        ++time;
        for(int rep = 0; rep < size; ++rep){
            int y = q.front().y;
            int x = q.front().x;
            int c = q.front().cost;
            bool flag = true;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < M && 0 <= ny && ny < N && buf[ny][nx] != '.'&&!visit[ny][nx]) {
                    if (buf[ny][nx] == 'B') {
                        printf("%d\n", c + 1);
                        return;
                    }
                    if ('0' <= buf[ny][nx] && buf[ny][nx] <= '9') {
                        if (l[buf[ny][nx]-'0'].dir && (i & 1)) {
                            visit[ny][nx]++;
                            q.push({ny, nx, c + 1});
                        }
                        else if (!l[buf[ny][nx]-'0'].dir && !(i & 1)) {
                            visit[ny][nx]++;
                            q.push({ny, nx, c + 1});
                        }
                        else if(flag){
                            flag = false;
                            q.push({y, x, c + 1});
                        }
                    }
                    if (buf[ny][nx] == '#') {
                        ++visit[ny][nx];
                        q.push({ny, nx, c + 1});
                    }
                }
            }
        }
        for(int i = 0; i <= lights; ++i){
            --l[i].time_left;
            if(!l[i].time_left){
                l[i].time_left = l[i].time[l[i].dir];
                l[i].dir^=1;
            }
        }
    }
    printf("impossible\n");
}
int main(){
    int n;
    char d;
    while(1) {
        scanf("%d %d",&N,&M);
        if(N==0&&M==0) break;
        lights = -1;
        for (int i = 0; i < N; ++i) {
            scanf("%s", buf[i]);
            for (int j = 0; j < M; ++j) {
                if (buf[i][j] == 'A') sx = j, sy = i;
                else if ('0' <= buf[i][j] && buf[i][j] <= '9') {
                    lights = max(lights, (buf[i][j] & 0b1111));
                }
            }
        }
        for (int i = 0; i <= lights; ++i) {
            scanf("%d %c", &n, &d);
            scanf("%d %d", &l[n].time[0], &l[n].time[1]);
            if (d == '-') l[n].dir = 1, l[n].time_left = l[n].time[0];
            else l[n].dir = 0, l[n].time_left = l[n].time[1];
        }
        BFS();
    }
}
