#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    int y;
    int x;
    int py;
    int px;
};
char buf[50][51];
bool visit[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N, M;
bool BFS(){
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j){
            if(!visit[i][j]){
                queue<INFO> q;
                INFO info;
                q.push({i,j,i,j});
                visit[i][j] = true;
                while(!q.empty()){
                    info = q.front();
                    q.pop();
                    for(int k=0; k<4; ++k){
                        int ny = info.y + dy[k];
                        int nx = info.x + dx[k];
                        if(0<=nx&&nx<M && 0<=ny&&ny<N && !(ny==info.py && nx==info.px) && buf[ny][nx]==buf[info.y][info.x]){
                            if(visit[ny][nx]) return true;
                            visit[ny][nx] = true;
                            q.push({ny,nx,info.y,info.x});
                        }
                    }
                }
            }
        }
    return false;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)
        scanf("%s",buf[i]);
    BFS() ? printf("Yes") : printf("No");
}
