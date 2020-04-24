#include <stdio.h>
#include <memory.h>
int dp[101][51];
int pSum[101];
int N, M, n;
int max(int a, int b){
    return a > b ? a : b;
}
int solution(int _n, int _m){
    if(!_m) return 0;
    if(_n<0) return -987654321;
    if(dp[_n][_m]!=-1) return dp[_n][_m];
    dp[_n][_m] = solution(_n-1,_m);
    for(int i = _n; i > 0; --i)
        dp[_n][_m] = max(dp[_n][_m],solution(i-2,_m-1)+pSum[_n]-pSum[i-1]);
    return dp[_n][_m];
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&N,&M);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &n);
        pSum[i] = pSum[i-1] + n;
    }
    printf("%d",solution(N,M));
    
}
