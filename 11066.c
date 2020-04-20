#include <stdio.h>
#include <memory.h>
#define INF 987654321
int dp[501][501];
int pages, cost[501];
int min(int a, int b){
    return a>b? b : a;
}
int f(int s, int e){
    if(dp[s][e]!=-1) return dp[s][e];
    dp[s][e] = INF;
    for(int i = s; i < e; ++i)
        dp[s][e] = min(dp[s][e],f(s,i)+f(i+1,e));
    dp[s][e] = dp[s][e] + cost[e] - cost[s-1];
    return dp[s][e];
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
        memset(dp,-1,sizeof(dp));
        scanf("%d",&pages);
        for(int i = 1; i <= pages; ++i)
            scanf("%d",&dp[i][i]), cost[i] = cost[i-1]+dp[i][i];
        printf("%d\n",f(1,pages)-cost[pages]);
    }
}
