#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    int y;
    int x;
    int item;
    int mv;
};
int N, M;
int v[50][50][32];
char buf[50][51];
int Pos[2], num, ans = 987654321;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<INFO> q;
int main(){
    scanf("%d %d",&M,&N);
    for(int i = 0; i < N; ++i){
        scanf("%s",buf[i]);
        for(int j = 0; j < M; ++j){
            if(buf[i][j]=='S') Pos[0] = i, Pos[1] = j;
            else if(buf[i][j]=='X') buf[i][j] = (num++|0b110000);
        }
    }
    q.push({Pos[0],Pos[1],0,1});
    v[Pos[0]][Pos[1]][0] = 1;
    num = (1<<num)-1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int item = q.front().item;
        int mv = q.front().mv;
        q.pop();
        if(v[y][x][item]!=mv) continue;
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<M && 0<=ny&&ny<N && buf[ny][nx]!='#'&& (!v[ny][nx][item]||v[ny][nx][item]>mv+1)){
                v[ny][nx][item] = mv+1;
                if(buf[ny][nx]=='E'){
                    if(item==num)
                        ans = ans > mv ? mv : ans;
                }
                else if('0'<=buf[ny][nx] && buf[ny][nx]<='5')
                    v[ny][nx][(item|(1<<(buf[ny][nx]&0b1111)))] = mv+1, q.push({ny,nx,(item|(1<<(buf[ny][nx]&0b1111))),mv+1});
                else q.push({ny,nx,item,mv+1});
            }
        }
    }
    printf("%d",ans);
}
