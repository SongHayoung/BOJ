#include <stdio.h>
#include <memory.h>
int val[1000];
int dp[1000][3];
int N;
int max(int a, int b){
    return a>b?a:b;
}
int f(int c,int dir){
    if(dp[c][dir]!=-1) return dp[c][dir];
    int leftmax = 0, rightmax = 0;
    dp[c][dir] = 0;
    switch(dir){
        case 0 :
            for (int i = 0; i < c; ++i) {
                if(val[i]>=val[c]) continue;
                leftmax = max(leftmax, f(i, 1));
            }
            for(int i = c+1; i < N; ++i) {
                if(val[i]>=val[c]) continue;
                rightmax = max(rightmax, f(i, 2));
            }
            break;
        case 1 :
            for (int i = 0; i < c; ++i) {
                if(val[i]>=val[c]) continue;
                leftmax = max(leftmax, f(i, 1));
            }
            break;
        case 2:
            for(int i = c+1; i < N; ++i) {
                if(val[i]>=val[c]) continue;
                rightmax = max(rightmax, f(i, 2));
            }
            break;
    }
    dp[c][dir] = leftmax + rightmax + 1;
    return dp[c][dir];
}
int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; ++i)
        scanf("%d",&val[i]);
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, f(i,0));
    printf("%d",ans);
}
