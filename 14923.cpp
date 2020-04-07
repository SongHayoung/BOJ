#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    int y;
    int x;
    int stick;
    int cost;
};
int N, M;
int v[1000][1000][2];
int buf[1000][1000];
int dst[2], ans = 987654321;
int x, y, stick, cost;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<INFO> q;
int main(){
    scanf("%d %d",&N,&M);
    scanf("%d %d",&y,&x);
    scanf("%d %d",&dst[0],&dst[1]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d",&buf[i][j]);
    --dst[0],--dst[1];
    q.push({y-1,x-1,1,1});
    v[y-1][x-1][1] = 1;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        stick = q.front().stick;
        cost = q.front().cost;
        q.pop();
        if(v[y][x][stick]!=cost) continue;
        for(int i = 0 ; i < 4 ; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<M && 0<=ny&&ny<N && (!v[ny][nx][stick]||v[ny][nx][stick]>v[y][x][stick]+1)){
                if(!buf[ny][nx]){
                    if(ny==dst[0]&&nx==dst[1]) ans = ans > cost+1 ? cost+1 : ans;
                    else {
                        v[ny][nx][stick] = cost + 1;
                        q.push({ny, nx, stick, cost + 1});
                    }
                }
                else if(stick){
                    if(ny==dst[0]&&nx==dst[1]) ans = ans > cost+1 ? cost+1 : ans;
                    else {
                        v[ny][nx][stick] = v[ny][nx][0] = cost + 1;
                        q.push({ny, nx, 0, cost + 1});
                    }
                }
            }
        }
    }
    ans==987654321 ? printf("-1") : printf("%d",--ans);
}
