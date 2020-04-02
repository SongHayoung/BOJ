#include <stdio.h>
#include <queue>
using namespace std;
struct ROBOT{
    int y;
    int x;
    int dir;
    int cmd;
};
int map[100][100];
int visit[100][100][4];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int M,N;
int dstx, dsty, dstr;
ROBOT r;
queue<ROBOT> q;
int main(void) {
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d",&map[i][j]);
    scanf("%d %d %d",&r.y,&r.x,&r.dir);
    scanf("%d %d %d",&dsty,&dstx,&dstr);
    r.cmd = 0; --r.y; --r.x; --dsty; --dstx;
    switch (r.dir){
        case 4: r.dir = 0; break;
        case 3: r.dir = 2; break;
        case 2: r.dir = 3; break;
    }
    switch (dstr){
        case 4: dstr = 0; break;
        case 3: dstr = 2; break;
        case 2: dstr = 3; break;
    }
    visit[r.y][r.x][r.dir] = 1;
    q.push(r);
    if(r.y==dsty && r.x == dstx && r.dir == dstr) {printf("%d",r.cmd); return 0;}
    while(!q.empty()){
        r = q.front();
        q.pop();
        for(int i = 1; i <= 3; ++i){
            int nx = r.x + i*dx[r.dir];
            int ny = r.y + i*dy[r.dir];
            if(0<=nx&&nx<M && 0<=ny&&ny<N && !map[ny][nx] && !visit[ny][nx][r.dir]){
                if(nx==dstx && ny==dsty && r.dir == dstr){
                    printf("%d",r.cmd+1);
                    return 0;
                }
                visit[ny][nx][r.dir] = 1;
                q.push({ny,nx,r.dir,r.cmd+1});
            }
            else if(0>nx||0>ny||nx>=M||ny>=N||map[ny][nx])
                break;
        }
        if(!visit[r.y][r.x][(r.dir+1)%4]){
            if(r.x== dstx && r.y == dsty && (r.dir+1)%4==dstr){
                printf("%d",r.cmd+1);
                return 0;
            }
            visit[r.y][r.x][(r.dir+1)%4] = 1;
            q.push({r.y,r.x,(r.dir+1)%4,r.cmd+1});
        }
        if(!visit[r.y][r.x][(r.dir+3)%4]){
            if(r.x== dstx && r.y == dsty && (r.dir+3)%4==dstr){
                printf("%d",r.cmd+1);
                return 0;
            }
            visit[r.y][r.x][(r.dir+3)%4] = 1;
            q.push({r.y,r.x,(r.dir+3)%4,r.cmd+1});
        }
    }
}
