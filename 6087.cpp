#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    short y,x,mirror,dir;
};
int W, H, ans = 987654321;
char buf[100][101];
short v[100][100][4];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
short pos[2][2], pos_idx;
int main(void){
    queue<INFO> q;
    scanf("%d %d",&W,&H);
    for(int i = 0; i < H; ++i){
        scanf("%s",buf[i]);
        for(int j = 0; j < W; ++j)
            if(buf[i][j]=='C')
                pos[pos_idx][0] = i, pos[pos_idx][1] = j, ++pos_idx;
    }
    v[pos[0][0]][pos[0][1]][0] = v[pos[0][0]][pos[0][1]][1] = v[pos[0][0]][pos[0][1]][2] = v[pos[0][0]][pos[0][1]][3] = 1;
    q.push({pos[0][0],pos[0][1],1,0});
    q.push({pos[0][0],pos[0][1],1,1});
    q.push({pos[0][0],pos[0][1],1,2});
    q.push({pos[0][0],pos[0][1],1,3});
    while(!q.empty()){
        INFO info = q.front();
        q.pop();
        if(info.mirror >= ans) continue;
        for(short i = 0; i < 4; ++i){
            if((info.dir+2)%4==i) continue;
            short nx = info.x + dx[i], ny = info.y + dy[i], nmirror = info.mirror;
            if(info.dir != i) ++nmirror;
            if(0<=nx&&nx<W && 0<=ny&&ny<H && (!v[ny][nx][i]||v[ny][nx][i]>nmirror) && buf[ny][nx]!='*'){
                v[ny][nx][i] = nmirror;
                if(ny==pos[1][0] && nx==pos[1][1])  ans = ans > nmirror ? nmirror : ans;
                else q.push({ny, nx, nmirror, i});
            }
        }
    }
    printf("%d",--ans);
}
