#include <stdio.h>
int N, M;
int map[1001][1001];
int dp[1001][1001];
int dpleft[1001];
int dpright[1001];
int max(int a, int b){
    return a>b ? a : b;
}
int main() {
    scanf("%d %d",&N, &M);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            scanf("%d",&map[i][j]);
    for(int i = 1; i <= M; ++i)
        dp[1][i] = map[1][i] + dp[1][i-1];
    for(int i = 2; i <= N; ++i) {
        dpleft[1] = dp[i][1] = dp[i-1][1] + map[i][1];
        for (int j = 2; j <= M; ++j)
            dpleft[j] = max(dp[i][j] = dp[i - 1][j] + map[i][j],dpleft[j-1]+map[i][j]);
        dpright[M] = dp[i][M];
        for (int j = M-1; j >= 1; --j)
            dpright[j] = max(dp[i][j],dpright[j+1]+map[i][j]);
        for(int j = 1; j <= M; ++j){
            dp[i][j] = max(dp[i][j],max(dpright[j],dpleft[j]));
        }
    }
    printf("%d",dp[N][M]);
}
