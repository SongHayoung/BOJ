# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
int dp[1500001];
short info[1500001][2];
int fRI(){
    int N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int main(void){
    register int N = fRI(), i;
    for(i = 0; i < N; ++i)
        info[i][0] = fRI(), info[i][1] = fRI();
    for(i = N-1; i >= 0; --i)
        dp[i] = info[i][0]+i>N ? dp[i+1] : dp[i+info[i][0]] + info[i][1] > dp[i+1] ? dp[i+info[i][0]] + info[i][1] : dp[i+1];
    printf("%d",dp[0]);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
