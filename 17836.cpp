#include <stdio.h>
#include <queue>
using namespace std;
struct INFO{
    int x;
    int y;
    int sword;
};
int map[100][100];
int visit[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int ans = 987654321;
int main(void) {
    int N,M,T;
    INFO info{0,0,0} , ninfo;
    queue<INFO> q;
    scanf("%d %d %d",&N,&M,&T);
    for(int i = 0 ; i < N; ++i)
        for(int j = 0; j < M; ++j)
            scanf("%d",&map[i][j]);
    q.push(info);
    visit[0][0] = 1;
    for(int i = 0; i <= T; ++i){
        int size = q.size();
        for(int j = 0; j < size; ++j){
            info = q.front();
            q.pop();
            for(int k = 0; k < 4; ++k){
                int nx = info.x + dx[k];
                int ny = info.y + dy[k];
                if(0<=nx && nx < M && 0<=ny && ny < N && !visit[ny][nx]){
                    if(!map[ny][nx]){
                        visit[ny][nx] = 1;
                        ninfo.x = nx, ninfo.y = ny, ninfo.sword = info.sword;
                        if(nx==M-1 && ny == N-1) ans = min(ans,i+1);
                        q.push(ninfo);
                    }
                    else if(map[ny][nx]==2){
                        visit[ny][nx] = 1;
                        ans = min(ans,i+N-1-ny+M-nx);
                    }
                }
            }
        }
    }
    if(ans==987654321||ans>T) printf("Fail");
    else printf("%d",ans);
}
