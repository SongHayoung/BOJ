#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int dp[100][100][80];
int n, m, k, ans;
string cmd;
string map[100];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int dpf(int y, int x, int cur) {
    if(cur == cmd.length() - 1)
        return 1;
    if(dp[y][x][cur] != -1) return dp[y][x][cur];
    dp[y][x][cur] = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= k; j++) {
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;
            if(0<= nx && nx < m && 0 <= ny && ny < n && map[ny][nx] == cmd[cur+1]) {
                dp[y][x][cur] += dpf(ny,nx,cur+1);
            }
        }
    }
    return dp[y][x][cur];
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < n; i++)
        cin>>map[i];
    cin>>cmd;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(map[i][j] == cmd[0])
                ans += dpf(i,j,0);
    printf("%d",ans);
}
