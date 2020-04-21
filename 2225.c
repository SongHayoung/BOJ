#include <stdio.h>
#include <memory.h>
long dp[201][201];
int N, K;
long f(int c, int l){
    if(dp[c][l]!=-1) return dp[c][l];
    dp[c][l] = 0;
    for(int i = 0; i <= N-c&&l!=K; ++i)
        dp[c][l] += f(c+i,l+1);
    dp[c][l]%=1000000000;
    return dp[c][l];
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&N,&K);
    dp[N][K]=1;
    printf("%ld",f(0,0));
}
