#include <stdio.h>
#include <queue>
using namespace std;
int R, C, N;
char buf[100][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
bool visit[100][100];
void pM(){
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            printf("%c",buf[i][j]);
        printf("\n");
    }
    printf("\n\n\n");
}
bool isdivied(int _y, int _x){
    int lv = _y;
    if(_y==R-1) return false;
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>> q;
    q.emplace(_y,_x);
    visit[_y][_x] = true;
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<C && 0<=ny&&ny<R && !visit[ny][nx] && buf[ny][nx] =='x'){
                visit[ny][nx] = true;
                lv = max(lv,ny);
                q.emplace(ny,nx);
            }
        }
    }
    return lv != R-1;
}
void simulation(int dir, int level){
    int x = -1, y = -1;
    if(dir&1){
        for(int i = C-1; i >= 0; --i){
            if(buf[R-level][i]=='x'){
                x = i; y = R-level;
                buf[y][x] = '.';
                break;
            }
        }
    }
    else{
        for(int i = 0; i < C; ++i){
            if(buf[R-level][i]=='x'){
                x = i; y = R-level;
                buf[y][x] = '.';
                break;
            }
        }
    }
    if(x==-1&&y==-1) return;
    for(int rep = 0; rep < 4; ++rep) {
        int nx = x + dx[rep];
        int ny = y + dy[rep];
        if(0<=nx && nx < C && 0<=ny && ny<R && buf[ny][nx]=='x') {
            if (isdivied(ny, nx)) {
                int down[100], downmin = 987654321;
                memset(down, -1, sizeof(down));
                for (int i = R - 1; i >= 0; --i)
                    for (int j = 0; j < C; ++j) {
                        if (visit[i][j] && down[j] == -1) {
                            down[j] = 0;
                            for (int k = i + 1; k < R && buf[k][j] == '.'; ++k) {
                                ++down[j];
                            }
                        }
                    }
                for (int i = 0; i < C; ++i) {
                    if (down[i] == -1) continue;
                    downmin = min(downmin, down[i]);
                }
                for (int i = R - 1; i >= 0; --i) {
                    for (int j = 0; j < C; ++j) {
                        if (visit[i][j] && buf[i][j] == 'x') {
                            buf[i + downmin][j] = 'x';
                            buf[i][j] = '.';
                        }
                    }
                }
            }
        }
    }
}
int main(void) {
    int level;
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i)
        scanf("%s",buf[i]);
    scanf("%d",&N);
    for(int i = 0; i < N; ++i){
        scanf("%d",&level);
        simulation(i,level);
    }
    pM();
}
