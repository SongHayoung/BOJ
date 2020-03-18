# pragma optimize("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#include <stdio.h>
#define gc() getchar_unlocked()
int DP[2001][2001];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b,a%b);
}
int main(void){
    register int d1,d2,i,j,g,ans = 0;
    d1 = fRI(); d2 = fRI();
    for(i = d1; i <= d2; ++i){
        for(j = 1; j <= i; ++j){
            g = gcd(i,j);
            if(!DP[i/g][j/g]) {++ans; DP[i/g][j/g] = 1;}
        }
    }
    printf("%d",ans);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
