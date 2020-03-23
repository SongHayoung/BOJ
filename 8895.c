# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
long long dp[21][21][21];
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int main(void){
    register short T = fRI(), n, r, l;
    dp[1][1][1] = 1;
    for(n = 2; n <= 20; ++n)
        for(l = 1; l <= n; ++l)
            for(r = 1; r <=n; ++r)
                dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + (n-2)*dp[n-1][l][r];
    while(T--){
        n = fRI(); l = fRI(); r = fRI();
        printf("%lld\n",dp[n][l][r]);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
