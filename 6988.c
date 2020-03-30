#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int nums[3001];
long dp[3001][3001];
int IDX[1000001];
int fastReadINT() {
    register int ret = 0, n = gc();
    for (; '0'>n || n>'9'; n = gc());
    do {
        ret = (ret << 3) + (ret << 1) + (n & 0b1111); n = gc();
    } while ('0' <= n);
    return ret;
}
long f(int from, int end, int flag){
    if(dp[from][end]!=-1) return dp[from][end];
    register int diff = nums[end]-nums[from];
    return dp[from][end] = nums[end]+diff>1000000||!IDX[nums[end]+diff] ? flag ?  nums[from] + nums[end] : 0 : nums[from] + f(end,IDX[nums[end]+diff],1);
}
int main(void) {
    register int N = fastReadINT(), i, j;
    memset(dp,-1,sizeof(dp));
    for(i = 1; i <= N; ++i)
        IDX[nums[i] = fastReadINT()] = i;
    long ans = 0;
    for(i = 1; i <= N; ++i)
        for(j = i+1; j <= N; ++j)
            ans = ans > f(i,j,0) ? ans : f(i,j,0);
    printf("%llu",ans);
}
