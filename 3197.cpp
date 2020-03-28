#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;
int R, C, maxday;
int lake[1500][1500];
bool visit[1500][1500];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int Dpos[2];
void INIT(){
    maxday = 0;
    queue<pair<int,int>> ice;
    char buf[1500][1501];
    for(int i = 0; i < R; ++i)
        scanf("%s",buf[i]);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j) {
            if(buf[i][j]=='L'||buf[i][j]=='.'){
                if(buf[i][j]=='L') lake[i][j] = -1,Dpos[0] = i, Dpos[1] = j;
                for(int k = 0; k < 4; ++k){
                    int nx = j+dx[k];
                    int ny = i+dy[k];
                    if(0<=nx&&nx<C && 0<=ny&&ny<R && buf[ny][nx]=='X' && !lake[ny][nx]){
                        lake[ny][nx] = 1;
                        ice.emplace(ny,nx);
                    }
                }
            }
            else continue;
        }
    while(!ice.empty()){
        int x = ice.front().second;
        int y = ice.front().first;
        maxday = max(maxday,lake[y][x]);
        ice.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<C && 0<=ny&&ny<R && buf[ny][nx]=='X' && !lake[ny][nx]){
                lake[ny][nx] = lake[y][x] + 1;
                ice.emplace(ny,nx);
            }
        }
    }
}
bool BFS(int day){
    queue<pair<int, int>> duck;
    memset(visit,false,sizeof(visit));
    duck.emplace(Dpos[0],Dpos[1]);
    visit[Dpos[0]][Dpos[1]] = true;
    while(!duck.empty()){
        int x = duck.front().second;
        int y = duck.front().first;
        duck.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<C && 0<=ny&&ny<R && !visit[ny][nx] && lake[ny][nx]<=day){
                if(lake[ny][nx] == -1) return true;
                visit[ny][nx] = true;
                duck.emplace(ny,nx);
            }
        }
    }
    return false;
}
int binary_search_BFS(){
    int l = 0, r = maxday;
    while(l+1<r) BFS((l+r)>>1) ? r = (l+r)>>1 : l = (l+r)>>1;
    return BFS(l) ? l : r;
}
int main(){
    scanf("%d %d",&R,&C);
    INIT();
    printf("%d",binary_search_BFS());
}
