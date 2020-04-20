#include <stdio.h>
#include <memory.h>
long long dp[31][31];
long long f(int w, int h){
    if(dp[w][h]!=-1) return dp[w][h];
    dp[w][h] = 0;
    if(w) dp[w][h] += f(w-1,h+1);
    if(h) dp[w][h] += f(w,h-1);
    return dp[w][h];
}
int main() {
    int tc;
    scanf("%d",&tc);
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 1;
    while(tc){
        printf("%lld\n",f(tc,0));
        scanf("%d",&tc);
    }
}
