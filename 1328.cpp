#include <stdio.h>
#include <memory.h>
#define MOD 1000000007
int dp[101][101][101];
long f(int n, int l, int r){
    return (n==r&&l==1)||(n==l&&r==1) ? 1 : !n||!l||!r ? 0 : dp[n][l][r]!=-1 ? dp[n][l][r] : dp[n][l][r] = ((f(n-1,l,r)*(n-2))%MOD + f(n-1,l-1,r) + f(n-1,l,r-1)) % MOD;
}
int main() {
    int N, L, R;
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d",&N, &L, &R);
    printf("%d",f(N,L,R));
}
