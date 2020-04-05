#include <stdio.h>
#include <queue>
using namespace std;
char buf[50][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N, M, ans;
void BFS(int _y, int _x){
    int visit[50][50] = {0,};
    int ret = 1;
    visit[_y][_x] = 1;
    queue<pair<int,int>> q;
    q.emplace(_y,_x);
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<M&&0<=ny&&ny<N && !visit[ny][nx] && buf[ny][nx]=='L'){
                visit[ny][nx] = visit[y][x] + 1;
                ret = visit[ny][nx];
                q.emplace(ny,nx);
            }
        }
    }
    ans = max(ans,ret);
}
int main(void){
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; ++i)
        scanf("%s",buf[i]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            if(buf[i][j]=='L'){
                if(j>0&&buf[i][j-1]!='L') BFS(i,j);
                else if(j<M-1&&buf[i][j+1]!='L') BFS(i,j);
                else if(i>0&&buf[i-1][j]!='L') BFS(i,j);
                else if(i<N-1&&buf[i+1][j]!='L') BFS(i,j);
            }
    printf("%d",--ans);
}
