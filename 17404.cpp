#include <iostream>
#include <memory.h>
using namespace std;
int cost[1000][3], n;
int dp[1000][3][3];
int start;
int dpf(int cur, int color) {
    if(dp[cur][color][start] != -1) return dp[cur][color][start];
    if(cur == n - 1)
        return color == start ? 987654321 : cost[cur][color];
    dp[cur][color][start] = 987654321;
    for(int i = 0; i < 3; i++)
        if(color != i)
            dp[cur][color][start] = min(dp[cur][color][start], dpf(cur+1, i));
    return dp[cur][color][start] += cost[cur][color];
}
int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d",&cost[i][0], &cost[i][1], &cost[i][2]);
    memset(dp, -1, sizeof(dp));
    int ans = 987654321;
    for(; start < 3; ++start)
        ans = min(ans, dpf(0,start));
    printf("%d",ans);
}
