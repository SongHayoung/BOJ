#include <stdio.h>
#define MOD 1000000007
#define MAX_N 4000000
#define ll long long
ll FACT[MAX_N+1];
ll REFACT[MAX_N+1];
ll getPOWED(ll N, ll P){
    ll result = 1;
    do{
        if(P&1==1){
            result *= N;
            result %= MOD;
        }
        N *= N;
        N %= MOD;
    }while(P>>=1);
    return result;
}
int main(void) {
    int N,R,i;
    FACT[1] = 1;
    scanf("%d %d",&N,&R);
    if(N==R||R==0){
        printf("1");
        return 0;
    }
    for(i = 2; i<=N; i++)
        FACT[i] = (FACT[i-1]*i)%MOD;
    REFACT[N] = getPOWED(FACT[N],MOD-2);
    R = N-R > R ? R : N-R;
    for(i=N-1; i>=R; i--)
        REFACT[i] = (REFACT[i+1]*(i+1))%MOD;
    printf("%lld",(((FACT[N]*REFACT[R])%MOD)*REFACT[N-R])%MOD);
}
