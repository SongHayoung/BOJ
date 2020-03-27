#include <stdio.h>
#include <memory.h>
#include <queue>
#include <algorithm>
#define INF 987654321
#define SH short
using namespace std;
struct INFO{
    int y;
    int x;
    vector<pair<int,int>> p;
};
int map[101][101];
short Apos[2][2];
int Bpos[2][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N, M;
int PREBFS(int y, int x, int dsty, int dstx){
    int v[101][101] = {0,};
    vector<pair<int,int>> p;
    p.emplace_back(y,x);
    INFO info{y,x,p};
    v[y][x] = 1;
    queue<INFO> q;
    q.push(info);
    while(!q.empty()){
        info = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            if(0<=nx && nx<=M && 0<=ny && ny<=N && !v[ny][nx] && !map[ny][nx]){
                if(nx==dstx && ny == dsty){
                    for(int i = 0; i < info.p.size(); ++i)
                        map[info.p[i].first][info.p[i].second] = 1;
                    map[ny][nx] = 1;
                    return info.p.size();
                }
                v[ny][nx] = 1;
                INFO ninfo {ny,nx,info.p};
                ninfo.p.emplace_back(ny,nx);
                q.push(ninfo);
            }
        }
    }
    return INF;
}
int BFS(int sy, int sx, int dsty, int dstx){
    queue<pair<int,int>> q;
    map[sy][sx] = 1;
    q.emplace(sy,sx);
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<= M && 0<=ny && ny<= N && !map[ny][nx]){
                if(nx==dstx && ny == dsty)
                    return map[y][x];
                q.emplace(ny,nx);
                map[ny][nx] = map[y][x]+1;
            }
        }
    }
    return INF;
}
int main(){
    int ans = INF;
    scanf("%d %d",&M,&N);
    scanf("%d %d %d %d",&Apos[0][1], &Apos[0][0], &Apos[1][1], &Apos[1][0]);
    scanf("%d %d %d %d",&Bpos[0][1], &Bpos[0][0], &Bpos[1][1], &Bpos[1][0]);
    
    map[Bpos[0][0]][Bpos[0][1]] = map[Bpos[1][0]][Bpos[1][1]] = INF;
    int dist = PREBFS(Apos[0][0],Apos[0][1],Apos[1][0],Apos[1][1]);
    map[Bpos[0][0]][Bpos[0][1]] = map[Bpos[1][0]][Bpos[1][1]] = 0;
    ans = min(BFS(Bpos[0][0],Bpos[0][1],Bpos[1][0],Bpos[1][1])+dist,ans);
    
    memset(map,0,sizeof(map));
    
    map[Apos[0][0]][Apos[0][1]] = map[Apos[1][0]][Apos[1][1]] = INF;
    dist = PREBFS(Bpos[0][0], Bpos[0][1], Bpos[1][0], Bpos[1][1]);
    map[Apos[0][0]][Apos[0][1]] = map[Apos[1][0]][Apos[1][1]] = 0;
    ans = min(BFS(Apos[0][0],Apos[0][1],Apos[1][0],Apos[1][1])+dist,ans);
    
    ans == INF ? printf("IMPOSSIBLE") : printf("%d",ans);
}
