#include <iostream>
#include <memory.h>
using namespace std;
int dp[100][100][2][2], w, h;
int move(int y, int x, int status, int dir) {
    if(y >= h || x >= w) return 0;
    if(dp[y][x][status][dir] != -1)
        return dp[y][x][status][dir];
    if(status) dp[y][x][status][dir] = dir ? move(y+1,x,status,dir) + move(y,x+1,status^1,dir ^ 1) : move(y+1,x,status^1, dir ^ 1) + move(y,x+1,status,dir);
    else dp[y][x][status][dir] = dir ? move(y+1,x,status^1,dir) : move(y,x+1,status^1,dir);
    dp[y][x][status][dir] %= 100000;
    return dp[y][x][status][dir];
}
int main() {
    scanf("%d %d",&w, &h);
    memset(dp,-1,sizeof(dp));
    dp[h-1][w-1][0][0] = dp[h-1][w-1][0][1] = dp[h-1][w-1][1][0] = dp[h-1][w-1][1][1] = 1;
    printf("%d",(move(1,0,1,1) + move(0,1,1,0)) % 100000);
}
