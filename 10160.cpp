#include<stdio.h>
int n,k;
long long dp[1000001];
int main(){
    scanf("%d %d",&n,&k);
    dp[0] = 1;
    for(register int i = 1; i <= 5; ++i) dp[i] = dp[i-1]*k;
    dp[5] = dp[4]*k - 2;
    dp[6] = ((dp[5]-2)*k)%1000000009;
    for(register int i = 7; i <= n; ++i){
        dp[i] = (k*dp[i-1] - (dp[i-5]<<1) + dp[i-7])%1000000009;
        if(dp[i]<0) dp[i]+=1000000009;
    }
    printf("%d",dp[n]);
}
