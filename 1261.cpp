#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;
char map[100][101];
int v[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int N, M;
int main() {
    scanf("%d %d",&M,&N);
    for(int i = 0; i < N; ++i)
        scanf("%s",map[i]);
    queue<tuple<int,int,int>> q;
    v[0][0] = 1;
    q.emplace(0,0,1);
    while(!q.empty()){
        int y, x, breaks;
        tie(y,x,breaks) = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<M && 0<=ny&&ny<N){
                if(map[ny][nx]=='0' && (!v[ny][nx]||v[ny][nx]>breaks)){
                    v[ny][nx] = breaks;
                    q.emplace(ny,nx,breaks);
                }
                if(map[ny][nx]=='1' && (!v[ny][nx]||v[ny][nx]>breaks+1)){
                    v[ny][nx] = breaks+1;
                    q.emplace(ny,nx,breaks+1);
                }
            }
        }
    }
    printf("%d",v[N-1][M-1]-1);
}
