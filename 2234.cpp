#include <stdio.h>
#include <queue>
using namespace std;
int map[50][50];
int map_convert[50][50];
int mapsize[2501], nums = 1, maxsize, extensionsize;
bool visit[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int N, M;
void BFS(){
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j){
            if(map_convert[i][j]) continue;
            queue<pair<int, int>> q;
            map_convert[i][j] = nums;
            ++mapsize[nums];
            q.emplace(i,j);
            while(!q.empty()){
                int x = q.front().second;
                int y = q.front().first;
                q.pop();
                for(int k = 0; k < 4; ++k){
                    if(map[y][x]&(1<<k)) continue;
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(0<=nx&&nx<M && 0<=ny&&ny<N && !map_convert[ny][nx]){
                        map_convert[ny][nx] = nums;
                        ++mapsize[nums];
                        q.emplace(ny,nx);
                    }
                }
            }
            maxsize = max(maxsize,mapsize[nums++]);
        }
    
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j){
            if(visit[i][j]) continue;
            queue<pair<int,int>> q;
            visit[i][j] = true;
            q.emplace(i,j);
            while(!q.empty()){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                for(int k = 0; k < 4; ++k){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(0<=nx&&nx<M && 0<=ny&&ny<N){
                        if(map_convert[ny][nx]==map_convert[i][j] && !visit[ny][nx]){
                            visit[ny][nx] = true;
                            q.emplace(ny,nx);
                        }
                        else if(map_convert[ny][nx]!=map_convert[i][j])
                            extensionsize = max(extensionsize,mapsize[map_convert[i][j]]+mapsize[map_convert[ny][nx]]);
                    }
                }
            }
        }
    printf("%d\n%d\n%d",nums-1,maxsize,extensionsize);
}
int main(){
    scanf("%d %d",&M,&N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d",&map[i][j]);
    BFS();
}
