#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;
int n, k;
int dp[501][501];
int point[500][2];
int calc(int p1, int p2) {
    return abs(point[p1][0] - point[p2][0]) + abs(point[p1][1] - point[p2][1]);
}
int dpf(int cur, int left) {
    if(cur == n-1) return 0;
    if(dp[cur][left]!=-1) return dp[cur][left];
    if(!left) return dp[cur][left] = dpf(cur+1,left) + calc(cur, cur + 1);
    dp[cur][left] = dpf(cur+1, left) + calc(cur, cur+1);
    for(int i = cur + 2; i < n && i < cur + left + 2; i++)
        dp[cur][left] = min(dp[cur][left], dpf(i, cur + left + 1 - i) + calc(cur, i));
    return dp[cur][left];
}
int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&point[i][0], &point[i][1]);
    memset(dp,-1,sizeof(dp));
    printf("%d",dpf(0,k));
}
