# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int dp[16][16], N, M;
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int dfs(int cx, int cy, int tx, int ty){
    if(dp[cy][cx]!=-1) return dp[cy][cx];
    dp[cy][cx] = 0;
    if(cy+1<=ty) dp[cy][cx] += dfs(cx,cy+1,tx,ty);
    if(cx+1<=tx) dp[cy][cx] += dfs(cx+1,cy,tx,ty);
    return dp[cy][cx];
}
int main(void){
    register int N = fRI(), M = fRI(), K = fRI(),i, j,cnt=0;
    memset(dp,-1,sizeof(dp));
    dp[N][M] = 1;
    
    if(K){
        for(i = 1 ; i <= N; i++)
            for(j = 1; j <= M; j++){
                ++cnt;
                if(!(cnt^K)){
                    dfs(j,i,M,N);
                    printf("%d",dfs(1,1,j,i));
                    return 0;
                }
            }
    }
    else
        printf("%d",dfs(1,1,M,N));
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
