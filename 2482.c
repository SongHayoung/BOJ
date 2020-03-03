#pragma GCC optimize ("O3")
#define MOD 1000000003
#include <stdio.h>
#include <memory.h>
int DP[1000][1000],N,K;
int solution(int n, int k,int is_zero){
    if(DP[k][n]!=-1) return DP[k][n];
    if(!k) return 1;
    int *ret = &DP[k][n];
    *ret = 0;
    int limit = N-((k-1)<<1);
    if(is_zero) --limit;
    for(int i = n+2; i<limit; i++)
        *ret = (*ret+solution(i,k-1,is_zero))%MOD;
    return *ret;
}
int main(void) {
    int answer = 0;
    scanf("%d %d",&N,&K);
    memset(DP,-1,sizeof(DP));
    answer = (answer+solution(0,K-1,1))%MOD;
    memset(DP,-1,sizeof(DP));
    for(int i=1;i<=N-(K<<1)+1;i++)
        answer = (answer+solution(i,K-1,0))%MOD;
    printf("%d",answer);
}
