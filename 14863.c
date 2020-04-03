#include <stdio.h>
#include <stdlib.h>
int N, K , wt, wc, bt, bc;
int dp[101][100001];
int main(void) {
    scanf("%d %d",&N,&K);
    scanf("%d %d %d %d",&wt,&wc,&bt,&bc);
    dp[1][wt] = wc;
    dp[1][bt] = dp[1][bt] > bc ? dp[1][bt] : bc;
    for(int i = 2; i <= N ; ++i) {
        scanf("%d %d %d %d", &wt, &wc, &bt, &bc);
        for(int j = 0; j <= K; ++j){
            if(!dp[i-1][j]) continue;
            if(j+wt<=K)
                dp[i][j+wt] = dp[i][j+wt] > dp[i-1][j] + wc ? dp[i][j+wt] : dp[i-1][j] + wc;
            if(j+bt<=K)
                dp[i][j+bt] = dp[i][j+bt] > dp[i-1][j] + bc ? dp[i][j+bt] : dp[i-1][j] + bc;
        }
    }
    int a = 0;
    for(int i = 0; i <= K; ++i)
        a = a > dp[N][i] ? a : dp[N][i];
    printf("%d",a);
}
