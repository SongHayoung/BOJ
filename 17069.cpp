#include <cstdio>
#include <memory.h>
using namespace std;
int map[32][32];
int N;
long long dp[32][32][3];
long long f(int y, int x,int pipe){
    if(dp[y][x][pipe]!=-1) return dp[y][x][pipe];
    dp[y][x][pipe] = 0;
    switch(pipe){
        case 0:
            if(x+1<N && !map[y][x+1]) dp[y][x][pipe] += f(y,x+1,0);
            if(x+1<N && y+1<N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1]) dp[y][x][pipe] += f(y+1,x+1,2);
            break;
        case 1:
            if(y+1<N && !map[y+1][x]) dp[y][x][pipe] += f(y+1,x,1);
            if(x+1<N && y+1<N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1]) dp[y][x][pipe] += f(y+1,x+1,2);
            break;
        case 2:
            if(x+1<N && !map[y][x+1]) dp[y][x][pipe] += f(y,x+1,0);
            if(y+1<N && !map[y+1][x]) dp[y][x][pipe] += f(y+1,x,1);
            if(x+1<N && y+1<N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1]) dp[y][x][pipe] += f(y+1,x+1,2);
            break;
    }
    return dp[y][x][pipe];
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d",&map[i][j]);
    dp[N-1][N-1][0] = dp[N-1][N-1][1] = dp[N-1][N-1][2] = 1;
    printf("%lld",f(0,1,0));
}
