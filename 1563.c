#include <stdio.h>
#include <memory.h>
#define MOD 1000000
int dp[1000][2][3];
int N;
int f(int d, int l, int a){
    if(d==N) return 1;
    if(dp[d][l][a]!=-1) return dp[d][l][a];
    dp[d][l][a] = f(d+1,l,0);
    if(!l) dp[d][l][a] += f(d+1,l+1,0);
    if(a!=2) dp[d][l][a] += f(d+1,l,a+1);
    dp[d][l][a] %= MOD;
    return dp[d][l][a];
}
int main(void) {
    scanf("%d",&N);
    memset(dp,-1,sizeof(dp));
    printf("%d",f(0,0,0));
    return 0;
}
