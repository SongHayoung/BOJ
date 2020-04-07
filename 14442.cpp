#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define gc() getchar_unlocked()
using namespace std;
struct INFO{
    int y;
    int x;
    int stick;
    int cost;
};
bool v[1000][1000][11];
int buf[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<INFO> q;
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int main(){
    register int N = fRI(),M = fRI(),K = fRI(),x,y,stick,cost, nx, ny, i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%1d", &buf[i][j]);
    q.push({0,0, K,1});
    if(N==1&&M==1) {printf("1"); exit(0);}
    v[0][0][K] = true;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        stick = q.front().stick;
        cost = q.front().cost;
        q.pop();
        for(i = 0 ; i < 4 ; ++i){
            nx = x + dx[i];
            ny = y + dy[i];
            if(0<=nx&&nx<M && 0<=ny&&ny<N && !v[ny][nx][stick]){
                if(!buf[ny][nx]){
                    if(ny==N-1&&nx==M-1) {printf("%d",cost+1); exit(0);}
                    else {
                        for(j = stick; j >= 0; --j)
                            v[ny][nx][j] = true;
                        q.push({ny, nx, stick, cost + 1});
                    }
                }
                else if(stick){
                    for(j = stick; j >= 0; --j)
                        v[ny][nx][j] = true;
                    q.push({ny, nx, stick-1, cost + 1});
                }
            }
        }
    }
    printf("-1");
}
