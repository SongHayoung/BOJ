#include <stdio.h>
long info[2];
long get5(long n){
    long ret = 0;
    for(long i = 5; i <= n; i*=5) ret += n/i;
    return ret;
}
long get2(long n){
    long ret = 0;
    for(long i = 2; i <= n; i<<=1) ret += n/i;
    return ret;
}
int main(){
    long N, M;
    scanf("%ld %ld",&N,&M);
    info[0] = get5(N) - get5(M) - get5(N-M);
    info[1] = get2(N) - get2(M) - get2(N-M);
    printf("%ld",info[0]>info[1] ? info[1] : info[0]);
}
